#include <iostream>
#include <aris.h>

#include "test_core_command.h"


using namespace aris::core;
const char xml_data[] =
"<HexapodIII>"
"	<Server ip = \"127.0.0.1\" port = \"5866\">"
"		<Commands type=\"command_pool_object\" default_child_type=\"command\">"
"			<start/>"
"			<stop/>"
"			<exit/>"
"			<en default_child_type=\"param\" default = \"all\">"
"				<all abbreviation = \"a\" />"
"				<first abbreviation = \"f\" />"
"				<second abbreviation = \"s\" />"
"				<motor abbreviation = \"m\" default = \"0\" />"
"				<physical_motor abbreviation = \"p\" default = \"0\" />"
"				<leg abbreviation = \"l\" default = \"0\" />"
"			</en>"
"			<ds default_child_type=\"param\" default = \"all\">"
"				<all abbreviation = \"a\" />"
"				<first abbreviation = \"f\" />"
"				<second abbreviation = \"s\" />"
"				<motor abbreviation = \"m\" default = \"0\" />"
"				<physical_motor abbreviation = \"p\" default = \"0\" />"
"				<leg abbreviation = \"l\" default = \"0\" />"
"			</ds>"
"			<hm default_child_type=\"param\" default = \"all\" >"
"				<all abbreviation = \"a\" />"
"				<first abbreviation = \"f\" />"
"				<second abbreviation = \"s\" />"
"				<motor abbreviation = \"m\" default = \"0\" />"
"				<physical_motor abbreviation = \"p\" default = \"0\" />"
"				<leg abbreviation = \"l\" default = \"0\" />"
"			</hm>"
"			<rc default = \"rc_param\">"
"				<rc_param type = \"group\" default_child_type=\"param\">"
"					<leg_param type = \"unique\" default_child_type=\"param\" default = \"all\">"
"						<all abbreviation = \"a\" />"
"						<first abbreviation = \"f\" />"
"						<second abbreviation = \"s\" />"
"						<leg abbreviation = \"l\" default = \"0\" />"
"					</leg_param>"
"					<t1 abbreviation = \"t\" default = \"3000\" />"
"					<t2 default = \"3000\" />"
"					<margin_offset abbreviation = \"m\" default = \"0.01\" />"
"				</rc_param>"
"			</rc>"
"			<wk default_child_type=\"param\" default = \"wk_param\">"
"				<wk_param type = \"group\" default_child_type=\"param\">"
"					<totalCount abbreviation = \"t\" default = \"3000\" />"
"					<n abbreviation = \"n\" default = \"1\" />"
"					<distance abbreviation = \"d\" default = \"0.5\" />"
"					<height abbreviation = \"h\" default = \"0.05\" />"
"					<alpha abbreviation = \"a\" default = \"0\" />"
"					<beta abbreviation = \"b\" default = \"0\" />"
"				</wk_param>"
"			</wk>"
"			<mv default_child_type=\"param\" default = \"mv_param\">"
"				<mv_param type = \"group\" default_child_type=\"param\" >"
"					<totalCount abbreviation = \"t\" default = \"10000\" />"
"					<mode_param type = \"unique\" default_child_type=\"param\" default = \"pin_param\">"
"						<pee_param type = \"group\" default_child_type=\"param\">"
"							<x abbreviation = \"x\" default = \"0\" />"
"							<y abbreviation = \"y\" default = \"0\" />"
"							<z abbreviation = \"z\" default = \"0\" />"
"							<A abbreviation = \"A\" default = \"0\" />"
"							<B abbreviation = \"B\" default = \"0\" />"
"							<C abbreviation = \"C\" default = \"0\" />"
"						</pee_param>"
"						<pin_param type = \"group\" default_child_type=\"param\">"
"							<motion_param type = \"unique\" default_child_type=\"param\" default = \"all\">"
"								<all abbreviation = \"a\" />"
"								<motion_id abbreviation = \"m\" default = \"0\" />"
"								<physical_id abbreviation = \"p\" default = \"0\" />"
"								<slave_id abbreviation = \"s\" default = \"0\" />"
"							</motion_param>"
"							<velocity abbreviation = \"v\" default = \"0\" />"
"							<force abbreviation = \"f\" default = \"no\" />"
"						</pin_param>"
"					</mode_param>"
"				</mv_param>"
"			</mv>"
"		</Commands>"
"	</Server>"
"</HexapodIII>";

void test_command()
{
	try
	{
		XmlDocument xml_doc;
        //xml_doc.Parse(xml_data);

		#ifdef UNIX
			xml_doc.LoadFile("/usr/aris/robot/resource/robot_motion.xml");
		#endif

		#ifdef WIN32
			xml_doc.LoadFile("C:\\aris\\robot\\resource\\robot_motion.xml");
		#endif

        

		std::unique_ptr<aris::core::CommandParser> parser_;
		parser_.reset(new aris::core::CommandParser());
		parser_->loadXml(xml_doc);

		//get all command of the system  
        std::cout << parser_->getHelpString() << std::endl;
		//display all command help information in detail
		for (auto &command : parser_->commandPool())
		{
            std::cout << command.getHelpString()<<std::endl;
		}

		//test the command param
        std::vector<std::string> cmd_string_vec{"en --all", "en -m=0 --all", "en -motor=0", "en --moto=0", "rc -t=3000","ds","start" };

		for (auto &cmd_string : cmd_string_vec)
		{
			try 
			{
				std::string cmd;
				std::map<std::string, std::string> params;
				parser_->parse(cmd_string, cmd, params);

				std::cout << cmd << std::endl;
				int paramPrintLength;
				if (params.empty())
				{
					paramPrintLength = 2;
				}
				else
				{
					paramPrintLength = std::max_element(params.begin(), params.end(), [](decltype(*params.begin()) a, decltype(*params.begin()) b)
					{
						return a.first.length() < b.first.length();
					})->first.length() + 2;
				}
				for (auto &i : params)
				{
					std::cout << std::string(paramPrintLength - i.first.length(), ' ') << i.first << " : " << i.second << std::endl;
				}

				std::cout << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl << std::endl;
			}
		}
	
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
}

