export module NodeFactory;

namespace parser {

export class NodeFactory {
public:
	static const NodeFactory& get_instance()
	{
		static NodeFactory instance;
		return instance;
	};
	NodeFactory(NodeFactory const&) = delete;
	void operator=(NodeFactory const&) = delete;

private:
	NodeFactory();
};

}
