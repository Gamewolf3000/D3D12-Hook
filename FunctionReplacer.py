import sys

def GetFunctionName(line):
	name_end_pos = line.find("(")
	name_start_pos = line.rfind(":", 0, name_end_pos) + 1
	return line[name_start_pos:name_end_pos:]

def GetArguments(line):
	parameters = line[line.find("(") + 1:line.find(")")]
	if parameters == "void":
		return "()"
	to_return = ""
	while "," in parameters:
		comma_pos = parameters.find(",")
		space_pos = parameters.rfind(" ", 0, comma_pos)
		to_return += parameters[space_pos + 1:comma_pos + 1:] + " "
		parameters = parameters[comma_pos + 1::]


	to_return += parameters[parameters.rfind(" ") + 1::]
	return "(" + to_return + ")"

def CreateNewCall(line):
	to_return = "\t" + ("return " if line[0:line.find(" "):] != "void" else "")
	to_return += caller + GetFunctionName(data[index - 1]) + GetArguments(data[index - 1])
	to_return += ";\n"
	return to_return


if len(sys.argv) != 2:
	print("Error: Expected to get filepath as argument and nothing else\nGot")
	if len(sys.argv) == 0:
		print("No arguments")
	else:
		for arg in sys.argv:
			print(arg)
else:
	caller = "real->"
	filename = sys.argv[1]
	file = open(filename, "r")
	data = file.readlines()

	for index in range(0, len(data)):
		if data[index] == "{\n":
			data[index + 1] = CreateNewCall(data[index - 1])

	file.close()
	file = open(filename, "w+")
	file.writelines(data)