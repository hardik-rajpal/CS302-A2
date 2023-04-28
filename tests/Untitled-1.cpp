
{
    "globalST" : [
        [
            "main", "fun",
            "global",
            0,
            0,
            "int"
        ],
        [
            "struct pair", "struct",
            "global",
            8,
            "-",
            "-"

        ]
    ],
                 "structs" : [
                     {
                         "name" : "struct pair",
                         "localST" : [

                             [
                                 "x", "var",
                                 "local",
                                 4,
                                 0,
                                 "int"
                             ],
                             [
                                 "y", "var",
                                 "local",
                                 4,
                                 4,
                                 "int"
                             ]
                         ]
                     }

                 ],
                             "functions" : [
                                 {
                                     "name" : "main",
                                     "localST" : [
                                         [
                                             "a", "var",
                                             "local",
                                             8,
                                             -8,
                                             "struct pair"
                                         ],
                                         [
                                             "b", "var",
                                             "local",
                                             8,
                                             -16,
                                             "struct pair"
                                         ],
                                         [
                                             "t0", "var",
                                             "local",
                                             4,
                                             -20,
                                             "struct pair*"
                                         ],
                                         [
                                             "t1", "var",
                                             "local",
                                             4,
                                             -24,
                                             "int*"
                                         ],
                                         [
                                             "t2", "var",
                                             "local",
                                             4,
                                             -28,
                                             "struct pair*"
                                         ],
                                         [
                                             "t3", "var",
                                             "local",
                                             4,
                                             -32,
                                             "int*"
                                         ],
                                         [
                                             "t4", "var",
                                             "local",
                                             4,
                                             -36,
                                             "struct pair*"
                                         ],
                                         [
                                             "t5", "var",
                                             "local",
                                             4,
                                             -40,
                                             "int*"
                                         ],
                                         [
                                             "t6", "var",
                                             "local",
                                             4,
                                             -44,
                                             "int"
                                         ],
                                         [
                                             "t7", "var",
                                             "local",
                                             4,
                                             -48,
                                             "struct pair*"
                                         ],
                                         [
                                             "t8", "var",
                                             "local",
                                             4,
                                             -52,
                                             "int*"
                                         ],
                                         [
                                             "t9", "var",
                                             "local",
                                             4,
                                             -56,
                                             "int"
                                         ]
                                     ],
                                     "ast" : {
                                         "seq" : [
                                             {"assignS" : {
                                                 "left" :
                                                     {"member" : {
                                                         "struct" :
                                                             {
                                                                 "identifier" : "a"
                                                             },
                                                         "field" :
                                                             {
                                                                 "identifier" : "x"
                                                             }
                                                     }},
                                                 "right" :
                                                     {
                                                         "intconst" : 10
                                                     }
                                             }},
                                             {"assignS" : {
                                                 "left" :
                                                     {"member" : {
                                                         "struct" :
                                                             {
                                                                 "identifier" : "a"
                                                             },
                                                         "field" :
                                                             {
                                                                 "identifier" : "y"
                                                             }
                                                     }},
                                                 "right" :
                                                     {
                                                         "intconst" : 12
                                                     }
                                             }},
                                             {"assignS" : {
                                                 "left" :
                                                     {
                                                         "identifier" : "b"
                                                     },
                                                 "right" :
                                                     {
                                                         "identifier" : "a"
                                                     }
                                             }},
                                             {"proccall" : {
                                                 "fname" :
                                                     {
                                                         "identifier" : "printf"
                                                     },
                                                 "params" : [
                                                     {"member" : {
                                                         "struct" :
                                                             {
                                                                 "identifier" : "b"
                                                             },
                                                         "field" :
                                                             {
                                                                 "identifier" : "y"
                                                             }
                                                     }},
                                                     {"member" : {
                                                         "struct" :
                                                             {
                                                                 "identifier" : "b"
                                                             },
                                                         "field" :
                                                             {
                                                                 "identifier" : "x"
                                                             }
                                                     }},
                                                     {
                                                         "stringconst" : "%d, %d"
                                                     }

                                                 ]
                                             }},
                                             {
                                                 "return" :
                                                     {
                                                         "intconst" : 0
                                                     }
                                             }

                                         ]
                                     }
                                 }

                             ]
}
