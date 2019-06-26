/**
* OpenAPI Petstore
* This is a sample server Petstore server. For this sample, you can use the api key `special-key` to test the authorization filters.
*
* The version of the OpenAPI document: 1.0.0
* 
*
* NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
* https://openapi-generator.tech
* Do not edit the class manually.
*/

#include "StoreApi.h"
#include "Helpers.h"

namespace org {
namespace openapitools {
namespace server {
namespace api {

using namespace org::openapitools::server::helpers;
using namespace org::openapitools::server::model;

StoreApi::StoreApi(std::shared_ptr<Pistache::Rest::Router> rtr) { 
    router = rtr;
};

void StoreApi::init() {
    setupRoutes();
}

void StoreApi::setupRoutes() {
    using namespace Pistache::Rest;

    Routes::Delete(*router, base + "/store/order/:orderId", Routes::bind(&StoreApi::delete_order_handler, this));
    Routes::Get(*router, base + "/store/inventory", Routes::bind(&StoreApi::get_inventory_handler, this));
    Routes::Get(*router, base + "/store/order/:orderId", Routes::bind(&StoreApi::get_order_by_id_handler, this));
    Routes::Post(*router, base + "/store/order", Routes::bind(&StoreApi::place_order_handler, this));

    // Default handler, called when a route is not found
    router->addCustomHandler(Routes::bind(&StoreApi::store_api_default_handler, this));
}

void StoreApi::delete_order_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {
    // Getting the path params
    auto orderId = request.param(":orderId").as<std::string>();
    
    try {
      this->delete_order(orderId, response);
    } catch (nlohmann::detail::exception &e) {
        //send a 400 error
        response.send(Pistache::Http::Code::Bad_Request, e.what());
        return;
    } catch (std::exception &e) {
        //send a 500 error
        response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
        return;
    }

}
void StoreApi::get_inventory_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {

    try {
      this->get_inventory(response);
    } catch (nlohmann::detail::exception &e) {
        //send a 400 error
        response.send(Pistache::Http::Code::Bad_Request, e.what());
        return;
    } catch (std::exception &e) {
        //send a 500 error
        response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
        return;
    }

}
void StoreApi::get_order_by_id_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {
    // Getting the path params
    auto orderId = request.param(":orderId").as<int64_t>();
    
    try {
      this->get_order_by_id(orderId, response);
    } catch (nlohmann::detail::exception &e) {
        //send a 400 error
        response.send(Pistache::Http::Code::Bad_Request, e.what());
        return;
    } catch (std::exception &e) {
        //send a 500 error
        response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
        return;
    }

}
void StoreApi::place_order_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {

    // Getting the body param
    
    Order body;
    
    try {
      nlohmann::json::parse(request.body()).get_to(body);
      this->place_order(body, response);
    } catch (nlohmann::detail::exception &e) {
        //send a 400 error
        response.send(Pistache::Http::Code::Bad_Request, e.what());
        return;
    } catch (std::exception &e) {
        //send a 500 error
        response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
        return;
    }

}

void StoreApi::store_api_default_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {
    response.send(Pistache::Http::Code::Not_Found, "The requested method does not exist");
}

}
}
}
}

