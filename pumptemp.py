#coding:utf-8
import xml.etree.cElementTree as ET
import codecs,sys

out_file = codecs.open("./Source/StepProtocol/StepHeadIDs.h", "w+", encoding="UTF-8-SIG")

curr_node = ET.Element("root")
curr_node.append(ET.parse("../Model/StepHeadID.xml").getroot())
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

out_file.write("#pragma once\n")
out_file.write("\n")
out_file.write("namespace step\n")
out_file.write("{\n")
out_file.write("	class StepHeadIDs\n")
out_file.write("	{\n")
out_file.write("	public:\n")
out_file.write("")
entry_name = "items"
parent1 = curr_node
curr_node = curr_node.find(entry_name)
parent_map[curr_node] = parent1

parentpumpid = pumpid
pumpid = -1
parent2 = curr_node
for node2 in curr_node:
    curr_node = node2
    parent_map[curr_node] = parent2
    pumpid += 1
    out_file.write("		static constexpr unsigned int ")
    out_file.write("%s" % get_attr(curr_node, "name"))
    out_file.write(" = ")
    out_file.write("%s" % get_attr(curr_node, "id"))
    out_file.write(";\n")
    out_file.write("")
    
pumpid = parentpumpid
if curr_node != parent2:
    curr_node = parent_map[curr_node]

curr_node = parent_map[curr_node]
out_file.write("	};\n")
out_file.write("}")
out_file.close()
