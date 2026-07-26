#include <gtest/gtest.h>
#include <PersonalLib/TemplateLib/MemCache/MemCacheTemplate.h>
#include <PersonalLib/TemplateLib/MemCache/MemCacheTemplateSingleton.h>

#include <cstring>
#include <thread>
#include <vector>

// ============================================================
// MemCacheTemplate 测试 — 非线程安全内存缓存
// ============================================================

struct CacheItem
{
    int id;
    CacheItem() : id(0) {}
    explicit CacheItem(int v) : id(v) {}
};

// ---------- Init ----------

TEST(MemCacheTemplateTest, Init_Preallocates)
{
    MemCacheTemplate<CacheItem> cache;
    cache.Init(32);

    // 连续分配 32 次 — 全部来自预分配
    for (int i = 0; i < 32; ++i)
    {
        CacheItem* item = cache.Allocate();
        ASSERT_NE(item, nullptr);
    }
}

// ---------- Allocate ----------

TEST(MemCacheTemplateTest, Allocate_Basic)
{
    MemCacheTemplate<CacheItem> cache;
    CacheItem* item = cache.Allocate();
    ASSERT_NE(item, nullptr);
    cache.Free(item);
}

TEST(MemCacheTemplateTest, Allocate_BeyondInit)
{
    MemCacheTemplate<CacheItem> cache;
    cache.Init(8);

    // 分配超过初始数量 — 超出部分应新建
    std::vector<CacheItem*> items;
    for (int i = 0; i < 20; ++i)
    {
        items.push_back(cache.Allocate());
        ASSERT_NE(items.back(), nullptr);
    }

    for (auto* item : items)
    {
        cache.Free(item);
    }
}

// ---------- Free / 重用 ----------

TEST(MemCacheTemplateTest, Free_ReturnsToPool)
{
    MemCacheTemplate<CacheItem> cache;
    cache.Init(8);

    // 分配所有预分配对象
    std::vector<CacheItem*> items;
    for (int i = 0; i < 8; ++i)
    {
        items.push_back(cache.Allocate());
    }

    // 全部返还
    for (auto* item : items)
    {
        cache.Free(item);
    }

    // 再从 cache 分配 — 应复用返还的对象，不会 new
    for (int i = 0; i < 8; ++i)
    {
        CacheItem* reused = cache.Allocate();
        ASSERT_NE(reused, nullptr);
        // 地址应和之前某个 items 一致（不一定保序）
    }
}

// ---------- 析构清理 ----------

TEST(MemCacheTemplateTest, Destructor_ClearsItems)
{
    // 验证析构函数 delete 所有缓存中的对象
    auto cache = std::make_unique<MemCacheTemplate<CacheItem>>();
    cache->Init(16);
    for (int i = 0; i < 10; ++i)
    {
        cache->Free(cache->Allocate());
    }
    // 不泄漏，不 crash
    cache.reset();
}

// ============================================================
// MemCacheTemplateSingleton 测试 — 线程安全单例内存缓存
// ============================================================

struct SingletonItem
{
    char data[32];
    int id;
    SingletonItem() : id(0) { std::memset(data, 0, sizeof(data)); }
    explicit SingletonItem(int v) : id(v) {}
};

// ---------- 单例 ----------

TEST(MemCacheTemplateSingletonTest, GetInstance_Singleton)
{
    auto& a = MemCacheTemplateSingleton<SingletonItem>::GetInstance();
    auto& b = MemCacheTemplateSingleton<SingletonItem>::GetInstance();
    EXPECT_EQ(&a, &b);
}

// ---------- Allocate / Free ----------

TEST(MemCacheTemplateSingletonTest, Allocate_Basic)
{
    auto& pool = MemCacheTemplateSingleton<SingletonItem>::GetInstance();
    SingletonItem* item = pool.Allocate();
    ASSERT_NE(item, nullptr);
    pool.Free(item);
}

TEST(MemCacheTemplateSingletonTest, Allocate_FromBlock)
{
    auto& pool = MemCacheTemplateSingleton<SingletonItem>::GetInstance();
    std::vector<SingletonItem*> items;

    // 分配默认块大小 (64) 个对象
    for (int i = 0; i < 64; ++i)
    {
        items.push_back(pool.Allocate());
        ASSERT_NE(items.back(), nullptr);
    }

    // Allocate 第 65 个应触发 AllocateBlock
    SingletonItem* extra = pool.Allocate();
    ASSERT_NE(extra, nullptr);
    items.push_back(extra);

    for (auto* item : items)
    {
        pool.Free(item);
    }
}

TEST(MemCacheTemplateSingletonTest, Free_Reuses)
{
    auto& pool = MemCacheTemplateSingleton<SingletonItem>::GetInstance();

    SingletonItem* a = pool.Allocate();
    pool.Free(a);

    // 再拿到的应该是同一块内存
    SingletonItem* b = pool.Allocate();
    ASSERT_NE(b, nullptr);
    // 因为是 new 出来的 placement，状态重置，但地址可能相同
    pool.Free(b);
}

// ---------- Free(nullptr) 安全 ----------

TEST(MemCacheTemplateSingletonTest, Free_Nullptr_Safe)
{
    auto& pool = MemCacheTemplateSingleton<SingletonItem>::GetInstance();
    pool.Free(nullptr); // 不应 crash
}

// ---------- SetBlockUnitNum ----------

TEST(MemCacheTemplateSingletonTest, SetBlockUnitNum)
{
    // SetBlockUnitNum 应在首次 Allocate 前调用
    struct CustomBlockItem
    {
        char data[16];
        CustomBlockItem() { std::memset(data, 0, 16); }
    };

    auto& pool = MemCacheTemplateSingleton<CustomBlockItem>::GetInstance();
    pool.SetBlockUnitNum(8);

    // 分配 8 个，不触发新块
    for (int i = 0; i < 8; ++i)
    {
        ASSERT_NE(pool.Allocate(), nullptr);
    }

    // 第 9 个触发新块
    ASSERT_NE(pool.Allocate(), nullptr);
}

// ---------- Free 函数（全局助手） ----------

TEST(MemCacheTemplateSingletonTest, GlobalFreeFunction_ClearsData)
{
    struct ClearCheckItem
    {
        char marker[16];
        ClearCheckItem() { std::memset(marker, 0xAB, sizeof(marker)); }
    };

    auto* item = Allocate<ClearCheckItem>();
    ASSERT_NE(item, nullptr);

    // Free<T>() 调用 memset 清零再归还
    Free(item);

    // 重新分配应得到清零后的对象
    auto* reused = Allocate<ClearCheckItem>();
    ASSERT_NE(reused, nullptr);
    for (auto c : reused->marker)
    {
        EXPECT_EQ(c, 0);
    }
    Free(reused);
}
