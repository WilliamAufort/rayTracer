#ifndef DEF_DRIVER
#define DEF_DRIVER

#include <istream>
#include "../include/camera.hpp"

namespace sceneParser {
	class Parser;
	class Lexer;

	class Driver
	{
		public:
		Driver();
		Driver(const Driver& other);
		Driver& operator= (const Driver& other);
		~Driver();

		Camera parse(std::string& fileName);
		Camera parse(std::istream& inputStream);

		void setResult(Camera& result);
	
		private:
		Lexer* lexer;
		Parser* parser;
		Camera result;

		friend class Parser;
		friend class Lexer;
};	}

#endif
