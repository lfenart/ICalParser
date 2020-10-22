module Parser;

import std.core;
import Ast;
import Exception;

namespace parser {

ast::Node::uptr ComponentParser::parse(std::istream& input) const
{
	ast::Component::uptr node = create_component();
	std::string line;
	for (;;) {
		auto tokens = read_tokens(input);
		if (!tokens.has_value()) {
			throw exception::UnexpectedEofError();
		}
		std::string token1 = tokens->first;
		std::string token2 = tokens->second;
		if (token1 == "END") {
			if (token2 != get_name()) {
				throw exception::UnexpectedComponentEndError(token2);
			}
			break;
		}
		if (token1 == "BEGIN") {
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
