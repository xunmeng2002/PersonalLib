#coding:utf-8
import xml.etree.cElementTree as ET
import codecs,sys

out_file = codecs.open("./Test/Source/Xtp/XtpPackages.cpp", "w+", encoding="UTF-8-SIG")

curr_node = ET.Element("root")
curr_node.append(ET.parse("./Model/Xtp/Xtp.xml").getroot())
curr_node.append(ET.parse("./Model/Types.xml").getroot())
parent_map = {}
pumpid = 0
parentpumpid = 0
target = 'target'
def get_attr(node, name):
    while node != None:
        if node.get(name) == None:
            if node in parent_map:
                node = parent_map[node]
            else:
                break
        else:
            return node.get(name)
    return ""

out_file.write("#include \"XtpPackages.h\"\n")
out_file.write("#include \"XtpUtility.h\"\n")
out_file.write("#include \"MemCacheTemplateSingleton.h\"\n")
out_file.write("#include <cstring>\n")
out_file.write("\n")
out_file.write("\n")
out_file.write("namespace xtp\n")
out_file.write("{\n")
out_file.write("")
entry_name = "xtp"
parent1 = curr_node
curr_node = curr_node.find(entry_name)
parent_map[curr_node] = parent1

entry_name = "packages"
parent2 = curr_node
curr_node = curr_node.find(entry_name)
parent_map[curr_node] = parent2

parentpumpid = pumpid
pumpid = -1
parent3 = curr_node
for node3 in curr_node:
    curr_node = node3
    parent_map[curr_node] = parent3
    pumpid += 1
    className = "Xtp" +  get_attr(curr_node, "name") + "Package"
    out_file.write(" \n")
    out_file.write("	")
    out_file.write("%s" % str(className))
    out_file.write("::")
    out_file.write("%s" % str(className))
    out_file.write("()\n")
    out_file.write("	{\n")
    out_file.write("		Head.PackageID = PackageID;\n")
    out_file.write("		Head.BodyLen = 0;\n")
    out_file.write("		Tail.CheckSum = 0;\n")
    out_file.write("		memset(&Field, 0, sizeof(Field));\n")
    out_file.write("	}\n")
    out_file.write("	")
    out_file.write("%s" % str(className))
    out_file.write("* ")
    out_file.write("%s" % str(className))
    out_file.write("::Allocate()\n")
    out_file.write("	{\n")
    out_file.write("		return ::Allocate<")
    out_file.write("%s" % str(className))
    out_file.write(">();\n")
    out_file.write("	}\n")
    out_file.write("	void ")
    out_file.write("%s" % str(className))
    out_file.write("::Free()\n")
    out_file.write("	{\n")
    out_file.write("		SessionID = 0;\n")
    out_file.write("		memset(IPAddress, 0, sizeof(IPAddressType));\n")
    out_file.write("		Head.BodyLen = 0;\n")
    out_file.write("		Tail.CheckSum = 0;\n")
    out_file.write("		memset(&Field, 0, sizeof(Field));\n")
    out_file.write("		MemCacheTemplateSingleton<")
    out_file.write("%s" % str(className))
    out_file.write(">::GetInstance().Free(this);\n")
    out_file.write("	}\n")
    out_file.write("	void ")
    out_file.write("%s" % str(className))
    out_file.write("::Prepare(SessionIDType sessionID)\n")
    out_file.write("	{\n")
    out_file.write("		SessionID = sessionID;\n")
    out_file.write("	}\n")
    out_file.write("	int ")
    out_file.write("%s" % str(className))
    out_file.write("::ToProtocolStream(char* buff, int size) const\n")
    out_file.write("	{\n")
    out_file.write("		memcpy(buff, &Field, sizeof(Field));\n")
    out_file.write("		return sizeof(Field);\n")
    out_file.write("	}\n")
    out_file.write("	bool ")
    out_file.write("%s" % str(className))
    out_file.write("::FromProtocolStream(char* buff, int size)\n")
    out_file.write("	{\n")
    out_file.write("		if (size != sizeof(Field))\n")
    out_file.write("		{\n")
    out_file.write("			return false;\n")
    out_file.write("		}\n")
    out_file.write("		memcpy(&Field, buff, sizeof(Field));\n")
    out_file.write("		return true;\n")
    out_file.write("	}\n")
    out_file.write("	const char* ")
    out_file.write("%s" % str(className))
    out_file.write("::GetString() const\n")
    out_file.write("	{\n")
    out_file.write("		return Field.GetString();\n")
    out_file.write("	}\n")
    out_file.write("	const char* ")
    out_file.write("%s" % str(className))
    out_file.write("::GetDebugString() const\n")
    out_file.write("	{\n")
    out_file.write("		return Field.GetDebugString();\n")
    out_file.write("	}\n")
    out_file.write("	\n")
    out_file.write("")
    
pumpid = parentpumpid
if curr_node != parent3:
    curr_node = parent_map[curr_node]

curr_node = parent_map[curr_node]

curr_node = parent_map[curr_node]
out_file.write("}\n")
out_file.write("")
out_file.close()
