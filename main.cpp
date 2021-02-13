#include <iostream>
#include <ignite/thin/ignite_client.h>
#include <ignite/thin/ignite_client_configuration.h>

int main([[maybe_unused]] int argc, [[maybe_unused]] char * argv[]){

    ignite::thin::IgniteClientConfiguration cfg;
    //cfg.SetEndPoints("40.88.137.77:10800");
    cfg.SetEndPoints("192.168.40.129:10800");
    try{
    ignite::thin::IgniteClient client = ignite::thin::IgniteClient::Start(cfg);

    ignite::thin::cache::CacheClient<std::string, std::string> cacheClient = client.GetOrCreateCache<std::string, std::string>("TestCache");
    cacheClient.Put("key 1","value 1");
    std::string result = cacheClient.Get("key 1");

    std::cout << "result: [" << result << "]" << std::endl; 
    }catch(ignite::IgniteError err){
        std::cout << "error:" <<err.what() << std::endl;
    }

    return 1;
}