import argparse


def file_to_bytes(file_path):
    with open(file_path, "rb") as f:
        return f.read()


def bytes_to_python_literal(bytes_data, line_length=60):
    hex_string = "".join(f"\\x{byte:02x}" for byte in bytes_data)
    lines = [hex_string[i : i + line_length] for i in range(0, len(hex_string), line_length)]
    return 'b"""\\\n' + "\\\n".join(lines) + '"""'


def main():
    parser = argparse.ArgumentParser(
        description="Convert a file to its Python bytes representation."
    )
    parser.add_argument("input_file", help="Path to the input file")
    args = parser.parse_args()

    bytes_data = file_to_bytes(args.input_file)
    python_literal = bytes_to_python_literal(bytes_data)
    print(python_literal)


if __name__ == "__main__":
    main()
