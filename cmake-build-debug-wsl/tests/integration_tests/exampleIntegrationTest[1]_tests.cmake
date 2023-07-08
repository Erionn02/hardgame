add_test( exampleIntegrationTest.EmptyTest /home/aczi/test/hardgame/cmake-build-debug-wsl/bin/exampleIntegrationTest [==[--gtest_filter=exampleIntegrationTest.EmptyTest]==] --gtest_also_run_disabled_tests)
set_tests_properties( exampleIntegrationTest.EmptyTest PROPERTIES WORKING_DIRECTORY /home/aczi/test/hardgame/cmake-build-debug-wsl/tests/integration_tests VS_DEBUGGER_WORKING_DIRECTORY)
set( exampleIntegrationTest_TESTS exampleIntegrationTest.EmptyTest)
