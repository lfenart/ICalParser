module Exception;

import std.core;

namespace exception {

UnexpectedEofError::UnexpectedEofError()
	: std::runtime_error("Unexpected EOF")
{
}

}
