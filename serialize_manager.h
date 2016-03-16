#include <cstddef> // NULL
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <boost/asio.hpp>
#include "session.h"
#include "boost/date_time/posix_time/posix_time.hpp" 

#include <boost/archive/tmpdir.hpp>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include <boost/serialization/base_object.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/assume_abstract.hpp>


#include "clientFile.h"

class serialize_manager{

	public:

	void save_client_file(const clientFile& file,const char* filename)
	{
		std::ofstream ofs(filename);
		    boost::archive::text_oarchive oa(ofs);
			    oa << file;
	}
};
