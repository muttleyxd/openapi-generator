/**
 * OpenAPI Petstore
 * This is a sample server Petstore server. For this sample, you can use the api key `special-key` to test the authorization filters.
 *
 * The version of the OpenAPI document: 1.0.0
 * 
 *
 * NOTE: This class is auto generated by OpenAPI-Generator 4.0.1-SNAPSHOT.
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

/*
 * StoreApi.h
 *
 * 
 */

#ifndef StoreApi_H_
#define StoreApi_H_


#include <memory>
#include <utility>
#include <corvusoft/restbed/session.hpp>
#include <corvusoft/restbed/resource.hpp>
#include <corvusoft/restbed/service.hpp>

#include "Order.h"
#include <map>
#include <string>

namespace org {
namespace openapitools {
namespace server {
namespace api {

using namespace org::openapitools::server::model;

class  StoreApi: public restbed::Service
{
public:
	StoreApi();
	~StoreApi();
	void startService(int const& port);
	void stopService();
};


/// <summary>
/// Delete purchase order by ID
/// </summary>
/// <remarks>
/// For valid response try integer IDs with value &lt; 1000. Anything above 1000 or nonintegers will generate API errors
/// </remarks>
class  StoreApiStoreOrderOrderIdResource: public restbed::Resource
{
public:
	StoreApiStoreOrderOrderIdResource();
    virtual ~StoreApiStoreOrderOrderIdResource();
    void DELETE_method_handler(const std::shared_ptr<restbed::Session> session);
    void GET_method_handler(const std::shared_ptr<restbed::Session> session);

	void set_callback_DELETE(
		std::function<std::pair<int, std::string>(
			std::string const &
		)> callback
	);

	void set_callback_GET(
		std::function<std::pair<int, std::string>(
			int64_t const &
		)> callback
	);

private:
	std::function<std::pair<int, std::string>(
		std::string const &
	)> callback_DELETE_ = nullptr;

	std::function<std::pair<int, std::string>(
		int64_t const &
	)> callback_GET_ = nullptr;
};

/// <summary>
/// Returns pet inventories by status
/// </summary>
/// <remarks>
/// Returns a map of status codes to quantities
/// </remarks>
class  StoreApiStoreInventoryResource: public restbed::Resource
{
public:
	StoreApiStoreInventoryResource();
    virtual ~StoreApiStoreInventoryResource();
    void GET_method_handler(const std::shared_ptr<restbed::Session> session);

	void set_callback_GET(
		std::function<std::pair<int, std::string>(
			
		)> callback
	);


private:
	std::function<std::pair<int, std::string>(
		
	)> callback_GET_ = nullptr;

};

/// <summary>
/// Place an order for a pet
/// </summary>
/// <remarks>
/// 
/// </remarks>
class  StoreApiStoreOrderResource: public restbed::Resource
{
public:
	StoreApiStoreOrderResource();
    virtual ~StoreApiStoreOrderResource();
    void POST_method_handler(const std::shared_ptr<restbed::Session> session);

	void set_callback_POST(
		std::function<std::pair<int, std::string>(
			std::shared_ptr<Order> const &
		)> callback
	);


private:
	std::function<std::pair<int, std::string>(
		std::shared_ptr<Order> const &
	)> callback_POST_ = nullptr;

};


}
}
}
}

#endif /* StoreApi_H_ */

