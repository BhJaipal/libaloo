import os

with open(f"{os.getcwd()}/cli/aloo", "r") as f:
	content = f.read()

if not "bin" in os.listdir(f"{os.getcwd()}"):
	os.mkdir(f"{os.getcwd()}/bin")

content = content.replace("$pwd$", os.getcwd())
with open(f"{os.getcwd()}/bin/aloo", "w") as f:
	f.write(content)

os.system("chmod +x bin/aloo")

with open(f"{os.getcwd()}/cli/aloo.sample.cpp", "r") as f:
	content = f.read()

content = content.replace("$pwd$", os.getcwd())
with open(f"{os.getcwd()}/cli/aloo.cpp", "w") as f:
	f.write(content)

with open(f"{os.getcwd()}/cli/aloo-cli.sample.cpp", "r") as f:
	content = f.read()

content = content.replace("$pwd$", os.getcwd())
with open(f"{os.getcwd()}/cli/aloo-cli.cpp", "w") as f:
	f.write(content)
