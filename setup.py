import os

with open(f"{os.getcwd()}/cli/aloo.sample.cpp", "r") as f:
	content = f.read()

content = content.replace("$pwd$", "/etc/aloo")
with open(f"{os.getcwd()}/cli/aloo.cpp", "w") as f:
	f.write(content)

with open(f"{os.getcwd()}/cli/aloo-cli.sample.cpp", "r") as f:
	content = f.read()

content = content.replace("$pwd$", "/etc/aloo")
with open(f"{os.getcwd()}/cli/aloo-cli.cpp", "w") as f:
	f.write(content)
