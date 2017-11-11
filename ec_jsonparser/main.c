//
//  main.c
//  ec_jsonparser
//
//  Created by LongFu on 2017/10/18.
//  Copyright © 2017年 Freelancer. All rights reserved.
//
//
#include <stdio.h>
#include "jsontree.h"
#include "jsonparse.h"


char jsontree[] = "{\
    \"act\": \"server\",\
    \"linkid\": \"xxxxxxxxx\",\
    \"type\": \"0|1\",\
    \"switchList\": [\
                   {\
                   \"times\": \"xxxxxx\",\
                   \"time\": \"2017-10-14 15:42:00\",\
                   \"enable\": \"0|1\"\
                   },\
                   {\
                   \"times\": \"--------\",\
                   \"time\": \"2017-10-14 15:42:00\",\
                   \"enable\": \"0|1\"\
                   }\
                   ],\
    \"sceneList\": [\
                  {\
                  \"time\": \"2017-10-14 15:42:00\",\
                  \"enable\": \"0|1\"\
                  },\
                  {\
                  \"time\": \"2017-10-14 15:42:00\",\
                  \"enable\": \"0|1\"\
                  }\
                  ]\
}";

//  这个SBjson解析裤看不懂

char json[] = "{\"name\":\"long\",\"user\":12}";
int lmainl(int argc, const char * argv[]) {
//    struct jsonparse_state state1;
//    printf("%s\n",json);
//    jsonparse_setup((struct jsonparse_state *)&state1, json, (int)strlen(json));
//    int type;
//    while ((type = jsonparse_next(&state1)) != 0) {
//        if (type == JSON_TYPE_PAIR_NAME)
//        {
//            if (jsonparse_strcmp_value(&state1, "name") == 0)
//            {
//                char buf[16] = { 0 };
//                jsonparse_next(&state1);
//                jsonparse_next(&state1);
//                jsonparse_copy_value(&state1, buf, sizeof(buf));
//                printf("buff %s\n",buf);
//            }
//
//            if (jsonparse_strcmp_value(&state1, "user") == 0)
//            {
//                int s;
//                jsonparse_next(&state1);
//                jsonparse_next(&state1);
//                s = jsonparse_get_value_as_int(&state1);
//                printf(" ---- == = %d\n",s);
//            }
//        }
//    }
    
    
    struct jsonparse_state json_state;

    printf("%s\n",jsontree);

    jsonparse_setup(&json_state, jsontree, strlen(jsontree));
    int type;
    while((type = jsonparse_next(&json_state)) != 0) {
        if (type == JSON_TYPE_PAIR_NAME) {
        if (jsonparse_strcmp_value(&json_state, "act") == 0)
        {
            char buf[16] = { 0 };
            jsonparse_next(&json_state);
            jsonparse_next(&json_state);
            jsonparse_copy_value(&json_state, buf, sizeof(buf));
            printf("act buff: %s --\n",buf);
        }

        if (jsonparse_strcmp_value(&json_state, "linkid") == 0)
        {
            char buf[16] = { 0 };
            jsonparse_next(&json_state);
            jsonparse_next(&json_state);
            jsonparse_copy_value(&json_state, buf, sizeof(buf));
            printf("linkid buff: %s\n",buf);
        }

        if (jsonparse_strcmp_value(&json_state, "type") == 0)
        {
            char buf[16] = { 0 };
            jsonparse_next(&json_state);
            jsonparse_next(&json_state);
            jsonparse_copy_value(&json_state, buf, sizeof(buf));
            printf("type buff: %s\n",buf);
        }
        
        if (type == JSON_TYPE_ARRAY && jsonparse_strcmp_value(&json_state, "switchList"))
        {
            printf("switchList JSON_TYPE_ARRAY\n");
            if (jsonparse_strcmp_value(&json_state, "times") == 0)
            {
                char buf[16] = { 0 };
                jsonparse_next(&json_state);
                jsonparse_next(&json_state);
                jsonparse_copy_value(&json_state, buf, sizeof(buf));
                printf("times buff %s\n",buf);
            }

            if (jsonparse_strcmp_value(&json_state, "time") == 0)
            {
                char buf[16] = { 0 };
                jsonparse_next(&json_state);
                jsonparse_next(&json_state);
                jsonparse_copy_value(&json_state, buf, sizeof(buf));
                printf("times buff %s\n",buf);
            }

            if (jsonparse_strcmp_value(&json_state, "enable") == 0)
            {
                char buf[16] = { 0 };
                jsonparse_next(&json_state);
                jsonparse_next(&json_state);
                jsonparse_copy_value(&json_state, buf, sizeof(buf));
                printf("enable buff %s\n",buf);
            }
        }
        
        if (type == JSON_TYPE_ARRAY && jsonparse_strcmp_value(&json_state, "sceneList"))
        {
            printf("sceneList JSON_TYPE_ARRAY\n");
            if (jsonparse_strcmp_value(&json_state, "time") == 0)
            {
                char buf[16] = { 0 };
                jsonparse_next(&json_state);
                jsonparse_next(&json_state);
                jsonparse_copy_value(&json_state, buf, sizeof(buf));
                printf("times buff %s\n",buf);
            }
            
            if (jsonparse_strcmp_value(&json_state, "enable") == 0)
            {
                char buf[16] = { 0 };
                jsonparse_next(&json_state);
                jsonparse_next(&json_state);
                jsonparse_copy_value(&json_state, buf, sizeof(buf));
                printf("enable buff %s\n",buf);
            }

        }
        }
    }
    return 0;
}

