#coding:utf-8
import xml.etree.cElementTree as ET
import codecs,sys

out_file = codecs.open("./Test/Source/Xtp/XtpPackageFactory.cpp", "w+", encoding="UTF-8-SIG")

curr_node = ET.Element("root")
curr_node.append(ET.parse("./Model/Xtp/Xtp.xml").getroot())
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

out_file.write("#include \"XtpPackageFactory.h\"\n")
out_file.write("#include \"XtpPackages.h\"\n")
out_file.write("\n")
out_file.write("\n")
out_file.write("\n")
out_file.write("namespace xtp\n")
out_file.write("{\n")
out_file.write("	XtpPackageBase* XtpPackageFactory::CreateXtpPackage(UShortType packageID)\n")
out_file.write("	{\n")
out_file.write("")
entry_name = "xtp"
parent1 = curr_node
curr_node = curr_node.find(entry_name)
parent_map[curr_node] = parent1

entry_name = "packages"
parent2 = curr_node
curr_node = curr_node.find(entry_name)
parent_map[curr_node] = parent2

out_file.write("		switch (packageID)\n")
out_file.write("		{\n")
out_file.write("")
parentpumpid = pumpid
pumpid = -1
parent3 = curr_node
for node3 in curr_node:
    curr_node = node3
    parent_map[curr_node] = parent3
    pumpid += 1
    out_file.write("		case Xtp")
    out_file.write("%s" % get_attr(curr_node, "name"))
    out_file.write("Package::PackageID:\n")
    out_file.write("		{\n")
    out_file.write("			return Xtp")
    out_file.write("%s" % get_attr(curr_node, "name"))
    out_file.write("Package::Allocate();\n")
    out_file.write("		}\n")
    out_file.write("")
    
pumpid = parentpumpid
if curr_node != parent3:
    curr_node = parent_map[curr_node]
out_file.write("		default:\n")
out_file.write("			break;\n")
out_file.write("		}\n")
out_file.write("")

curr_node = parent_map[curr_node]

curr_node = parent_map[curr_node]
out_file.write("		return nullptr;\n")
out_file.write("	}\n")
out_file.write("}\n")
out_file.write("")
out_file.close()
