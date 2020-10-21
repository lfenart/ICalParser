import std.core;
import std.regex;
import Parser;
import Exception;

std::regex folded_line("\n\\s");

std::string read_file(const char* path)
{
	std::ifstream input_file(path);
	if (!input_file.is_open()) {
		throw "Could not open file";
	}
	std::string input;
	input.assign((std::istreambuf_iterator<char>(input_file)),
		(std::istreambuf_iterator<char>()));
	input_file.close();
	return input;
}

void remove_folded_lines(std::string& input)
{
	input = std::regex_replace(input, folded_line, "");
}

int main(int argc, char* argv[])
{
	if (argc < 2) {
		std::cerr << "Error: Not enough arguments" << std::endl;
		return 1;
	}
	std::string input = read_file(argv[1]);
	remove_folded_lines(input);
	std::stringstream ss(input);
	parser::ICalParser p;
	try {
		auto node = p.parse(ss);
		auto visitor = std::make_shared<ast::XmlVisitor>(std::cout);
		node->accept(visitor);
	} catch (std::runtime_error e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
