#include <gtest/gtest.h>
#include <ignite/thin/ignite_client.h>
#include <ignite/thin/ignite_client_configuration.h>

TEST(test_basic, basic_test_set)
{
    ignite::thin::IgniteClientConfiguration cfg;
    cfg.SetEndPoints("192.168.40.129:10800");
    try{
    ignite::thin::IgniteClient client = ignite::thin::IgniteClient::Start(cfg);

    ignite::thin::cache::CacheClient<std::string, std::string> cacheClient = client.GetOrCreateCache<std::string, std::string>("TestCache");
    cacheClient.Put("key 1","value 1");
    std::string result = cacheClient.Get("key 1");

    ASSERT_TRUE(result=="value 1");    
    }catch(ignite::IgniteError err){
        std::cout << "error:" <<err.what() << std::endl;
        ASSERT_TRUE(false);
    }
    
}




int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}