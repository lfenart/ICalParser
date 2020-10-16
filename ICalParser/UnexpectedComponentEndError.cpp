module Exception;

import std.core;

namespace exception {

UnexpectedComponentEndError::UnexpectedComponentEndError(std::string component_name)
	: std::runtime_error("Unexpected component end: " + component_name)
{
}

}
