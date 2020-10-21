module Parser;

import std.core;
import Ast;
import Exception;

namespace parser {

ast::Node::uptr ComponentParser::parse(std::istream& input) const
{
	ast::Component::uptr node = create_node();
	std::string line;
	for (;;) {
		if (!std::getline(input, line)) {
			throw exception::UnexpectedEofError();
		}
		auto pos = line.find(":");
		if (pos == std::string::npos) {
			throw exception::MissingColonError();
		}
		std::string token1 = line.substr(0, pos);
		std::string token2 = line.substr(pos + 1);
		if (std::strcmp("END", token1.c_str()) == 0) {
			if (std::strcmp(get_name(), token2.c_str()) != 0) {
				throw exception::UnexpectedComponentEndError(token2);
			}
			break;
		}
		if (std::strcmp("BEGIN", token1.c_str()) == 0) {
			try {
				ast::Node::uptr child = get_component_parsers().at(token2)->parse(input);
				node->add_component(ast::Component::uptr(dynamic_cast<ast::Component*>(child.release())));
			} catch (const std::out_of_range&) {
				std::cerr << "Skipping unknown component: " << token2 << std::endl;
				parse_unknown_component(input, token2.c_str());
			}
		} else {
			// TODO
			std::cerr << "Skipping unknown property: " << token1 << std::endl;
		}
	}
	return node;
}

const std::map<std::string, std::unique_ptr<ComponentParser>>& ComponentParser::get_component_parsers() const
{
	return component_parsers;
}

void ComponentParser::add_component_parser(std::string name, std::unique_ptr<ComponentParser> parser)
{
	component_parsers[name] = std::move(parser);
}

}
