if(EXISTS "/home/aczi/test/hardgame/build/tests/unit_tests/exampleUnitTest2[1]_tests.cmake")
  include("/home/aczi/test/hardgame/build/tests/unit_tests/exampleUnitTest2[1]_tests.cmake")
else()
  add_test(exampleUnitTest2_NOT_BUILT exampleUnitTest2_NOT_BUILT)
endif()
