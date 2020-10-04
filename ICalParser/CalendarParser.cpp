module CalendarParser;

import std.core;
import Node;

namespace parser {

std::unique_ptr<ast::Node> CalendarParser::parse(std::istream& input) const
{
	std::unique_ptr<ast::Node> node = get_factory().create_node_calendar();
	std::string line;
	for (;;) {
		if (!std::getline(input, line)) {
			std::cerr << "Unexpected eof" << std::endl;
			exit(1);
		}
		auto pos = line.find(":");
		if (pos == std::string::npos) {
			std::cerr << "':' not found, skipping line" << std::endl;
		} else {
			std::string token1 = line.substr(0, pos);
			std::string token2 = line.substr(pos + 1);
			if (std::strcmp("END", token1.c_str()) == 0) {
				if (std::strcmp("VCALENDAR", token2.c_str()) == 0) {
					break;
				} else {
					/*std::cerr << "Unexpected end of component" << std::endl;
					exit(1);*/
				}
			}
			if (std::strcmp("BEGIN", token1.c_str()) == 0) {
				// parse component
				std::cout << "Parse component" << std::endl;
			} else {
				std::cout << "Parse property" << std::endl;
			}
		}
	}
	return node;
}

}
