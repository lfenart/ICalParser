export module Ast;

import std.core;

namespace ast {

export class Node;
export class ICal;
export class VCalendar;
export class Component;
export class NodeFactory;

class Node {
public:
	using sptr = std::shared_ptr<Node>;
	using uptr = std::unique_ptr<Node>;

	virtual ~Node() = default;
};

class Component : public Node {
public:
	using sptr = std::shared_ptr<Component>;
	using uptr = std::unique_ptr<Component>;

	virtual ~Component() = default;

	const std::vector<Component::uptr>& get_components() const;

private:
	std::vector<Component::uptr> components;
};

class VCalendar : public Component {
public:
	using sptr = std::shared_ptr<VCalendar>;
	using uptr = std::unique_ptr<VCalendar>;

	VCalendar() = default;
	virtual ~VCalendar() = default;
};

class ICal : public Node {
public:
	using sptr = std::shared_ptr<ICal>;
	using uptr = std::unique_ptr<ICal>;

	ICal() = default;
	virtual ~ICal() = default;

	const std::vector<VCalendar::uptr>& get_calendars() const;
	void add_calendar(VCalendar::uptr);

private:
	std::vector<VCalendar::uptr> calendars;
};

class NodeFactory {
public:
	VCalendar::uptr create_node_calendar() const;
	ICal::uptr create_node_ical() const;
};

}
