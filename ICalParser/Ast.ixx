export module Ast;

import std.core;

namespace ast {

export class Node;
export class ICal;
export class VCalendar;
export class VComponent;

class Node {
public:
	using sptr = std::shared_ptr<Node>;
	using uptr = std::unique_ptr<Node>;

	virtual ~Node() = default;
};

class VComponent : public Node {
public:
	using sptr = std::shared_ptr<VComponent>;
	using uptr = std::unique_ptr<VComponent>;

	virtual ~VComponent() = default;

	const std::vector<VComponent::uptr>& get_components() const;

private:
	std::vector<VComponent::uptr> components;
};

class VCalendar : public Node {
public:
	using sptr = std::shared_ptr<VCalendar>;
	using uptr = std::unique_ptr<VCalendar>;

	VCalendar() = default;
	virtual ~VCalendar() = default;

	const std::vector<VComponent::uptr>& get_components() const;

private:
	std::vector<VComponent::uptr> components;
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
	std::vector<std::unique_ptr<VCalendar>> calendars;
};

}
