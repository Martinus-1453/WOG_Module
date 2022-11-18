import sys
import os
import re


def main(argv, arc):
    if arc != 2:
        print(f"Usage: {argv[0]} ClassHeader.h")
        return

    header_path = argv[1]
    header_name = os.path.basename(header_path).removesuffix('.h')
    print(header_name)

    file = open(header_path, 'r', encoding='utf8')

    lines = file.readlines()

    last_line = 0
    class_name = None
    # Search class name
    for idx, line in enumerate(lines):
        last_line = idx
        class_name_match = re.search(rf"class {header_name} : public Class", line)
        if class_name_match:
            class_name = header_name
            break

    # No class_name in header file!
    if class_name is None:
        print("No suitable class in header file!")
        return

    class_ctor = []
    methods = []
    properties = []

    for idx, line in enumerate(lines, last_line):
        class_ctor_match = re.search(rf'(?<={class_name}\()()()(.*)(?=\);)', line)
        method_match = re.search(r'(?<=Function)(.*>)(\s?)(.*)(?=;)', line)
        property_match = re.search(r'(?<=Property)(.*>)(\s?)(.*)(?=;)', line)

        if class_ctor_match:
            class_ctor.append(class_ctor_match.group())
        elif method_match:
            methods.append(method_match.group(3))
        elif property_match:
            properties.append(property_match.group(3))

    new_class_line = \
f"""#include \"pch.h\"
#include \"{class_name}.h\"
        
namespace nonut::g2o
{{"""

    for ctor in class_ctor:
        new_class_line += \
f"""
\t{class_name}::{class_name}({ctor}) :
\t\tClass(\"{class_name}\"),
"""

        for method in methods:
            new_class_line += f"\t\tMETHOD_CTOR({method}),\n"

        for prop in properties:
            new_class_line += f"\t\tPROPERTY_CTOR({prop}),\n"

        new_class_line = new_class_line[:-2]

        ctor_arg_names = ctor.split(',')
        args = ""
        for arg in ctor_arg_names:
            args += f"{arg.split()[-1:][0]}, "

        new_class_line += f"""\n\t{{
\t\tclassCtor({args.strip().removesuffix(',')});
\t}}\n"""

    new_class_line += "}\n"

    dir_path = os.path.dirname(os.path.realpath(header_path))
    new_class_file = open(os.path.join(dir_path, f'{header_name}.cpp'), 'w', encoding='utf8')
    new_class_file.write(new_class_line)


if __name__ == '__main__':
    main(sys.argv, len(sys.argv))
