void setUp(){

}
void tearDown(){

}

void test1(void){
TEST_ASSERT_EQUAL_FLOAT();
}
int main(void){
    UNITY_BEGIN();
    RUN_TEST(test1);

    return UNITY_END();

}