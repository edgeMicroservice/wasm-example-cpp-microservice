#include <init.hpp>
#include <api.hpp>

using cppjson = nlohmann::json;

using namespace mimik::wasm;
using namespace mimik::wasm::model;
using namespace mimik::wasm::api;

#if 1
 void http_event_handler(const http_event &evt) {
   http_client_option option;
   option.method = "GET";
   option.url =
       "https://timeapi.io/api/Time/current/zone?timeZone=Europe/Amsterdam";

   httpclient().fetch(option, [](const model::callback_error_ptr &error,
                                 const model::callback_result &result) {
     if (error) {
       cppjson doc;
       doc["error_message"] = error->message;
       response().send(doc.dump());
     } else {
       response().send(result.data);
     }
   });
 }
#endif

#if 0
void http_event_handler(const http_event &evt) {
  cppjson doc;

  doc["message"] = "hello world";
  auto data = doc.dump();

  response().send(data);
}
#endif

int main() {
  init_mk_module_event_handler({http_event_handler});
  return 0;
}
