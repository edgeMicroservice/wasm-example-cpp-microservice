#include <init.hpp>
#include <api.hpp>

#include <iostream>
#include <ctime>

using cppjson = nlohmann::json;

using namespace mimik::wasm;
using namespace mimik::wasm::model;
using namespace mimik::wasm::api;

void http_event_handler(const http_event& evt) {
  // current date/time based on current system
  time_t now = time(0);

  // convert now to string form
  char* dt = ctime(&now);

  cppjson doc;

  doc["current_time"] = dt;
  auto data = doc.dump();

  response().send(data);
}

int main() {
  init_mk_module_event_handler({http_event_handler});
  return 0;
}
