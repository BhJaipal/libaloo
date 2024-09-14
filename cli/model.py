#!/usr/bin/env python3
import os
import json
import re
import sys

def create_model(argv):
	if not argv:
		raise Exception("No name is provided")

	match = re.match(r'([a-zA-Z]+)', argv[0])

	if match is None:
		raise Exception("Name must be only alphabets")
	if match.group(0) != argv[0]:
		raise Exception("Invalid name " + argv[0])
	if len(argv) == 1:
		raise Exception("No properties are provided")

	model_types = ["string", "int", "float", "bool"]
	model_name = argv[0]

	model_props = []
	for arg in argv[1:]:
		if ":" not in arg:
			raise Exception("Invalid property " + arg)
		key, type_ = arg.split(":")
		for element in key:
			if not (element.isalpha()):
				raise Exception("Invalid token " + element + " in " + key)
		for element in type_:
			if not (element.isalpha()):
				raise Exception(f"Invalid token '{element}' in {type_}")
		if type_ not in model_types:
			raise Exception(f"Invalid type '{type_}'")

		model_props.append({'key': key, 'type': type_})

	escSeq = "\n\t"
	type_switch = {
		"string": "char*",
		"bool": "_Bool",
		"int": "int",
		"float": "float",
	}
	content = f"""#include "aloo.h"
#include <stdbool.h>

typedef struct _{model_name} {{
	int id;
	{escSeq.join([type_switch[prop['type']] + " " + prop['key'] for prop in model_props])}
}} {model_name};
"""

	models_dir = os.path.join(os.getcwd(), "models")
	if not os.path.exists(models_dir):
		os.mkdir(models_dir)

	model_file_path = os.path.join(models_dir, f"{argv[0]}.h")
	if not os.path.exists(model_file_path):
		with open(model_file_path, 'w') as f:
			f.write(content)

		with open(os.path.join(os.getcwd(), "aloo.json"), 'r') as f:
			aloo = json.load(f)

		if "models" in aloo:
			aloo["models"].append({
				"modelName": model_name,
				"members": [{"member": prop['key'], "type": prop['type']} for prop in model_props],
			})
		else:
			aloo["models"] = [{
				"modelName": model_name,
				"members": [{"member": prop['key'], "type": prop['type']} for prop in model_props],
			}]

		with open(os.path.join(os.getcwd(), "aloo.json"), 'w') as f:
			json.dump(aloo, f)
	else:
		raise Exception("Model '" + model_name + "' already exists")

create_model(sys.argv[1:])