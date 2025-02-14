#include <Spark.h>

class Sandbox : public Spark::App {
	public:
		Sandbox() {}
		~Sandbox() {}
};

Spark::App* Spark::CreateApp() {
	return new Sandbox();
}
