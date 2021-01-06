import std.core;
import Parser;
import Exception;

int main(int argc, char* argv[])
{
	if (argc < 2) {
		std::cerr << "Error: Not enough arguments" << std::endl;
		return 1;
	}
	std::ifstream input(argv[1]);
	parser::ICalParser p;
	try {
		auto node = p.parse(input);
		std::ostream* xml_out = &std::cout;
		std::ofstream xml_fout;
		if (argc > 2) {
			xml_fout.open(argv[2]);
			xml_out = &xml_fout;
		}
		//auto visitor = std::make_shared<ast::XmlVisitor>(*xml_out);
		auto visitor = std::make_shared<ast::RoomOccupancyVisitor>(*xml_out);
		node->accept(visitor);
	} catch (std::runtime_error e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
