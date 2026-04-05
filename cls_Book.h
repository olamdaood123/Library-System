#pragma once
#include <iostream>
#include "cls_Media.h"
using namespace std;
class cls_Book : public cls_Media
{
        public :
		string author;
		int pages;
};

