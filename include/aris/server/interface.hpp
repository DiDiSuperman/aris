﻿#ifndef ARIS_SERVER_INTERFACE_H_
#define ARIS_SERVER_INTERFACE_H_

#include <string>
#include <sstream>
#include <map>
#include <memory>
#include <future>

#include <aris/core/core.hpp>
#include <aris/control/control.hpp>
#include <aris/sensor/sensor.hpp>
#include <aris/dynamic/dynamic.hpp>
#include <aris/plan/plan.hpp>

namespace aris::server
{
	class InterfaceRoot : public aris::core::Object
	{
	public:
		auto virtual saveXml(aris::core::XmlElement &xml_ele) const->void override;
		auto virtual loadXml(const aris::core::XmlElement &xml_ele)->void override;

		ARIS_REGISTER_TYPE(InterfaceRoot);

	private:
		aris::core::XmlDocument doc_;
	};
	
	
	
	auto parse_ret_value(std::vector<std::pair<std::string, std::any>> &ret)->std::string;
	
	
	class Interface :public aris::core::Object
	{
	public:
		auto virtual open()->void = 0;
		auto virtual close()->void = 0;

		Interface(const std::string &name = "interface");
		ARIS_REGISTER_TYPE(Interface);
		ARIS_DEFINE_BIG_FOUR(Interface);
	};

	class WebInterface :public Interface
	{
	public:
		auto virtual open()->void override;
		auto virtual close()->void override;
		auto virtual loadXml(const aris::core::XmlElement &xml_ele)->void override;

		WebInterface(const std::string &name = "interface", const std::string &port = "5866", aris::core::Socket::TYPE type = aris::core::Socket::WEB);
		ARIS_REGISTER_TYPE(WebInterface);
		ARIS_DEFINE_BIG_FOUR(WebInterface);

	private:
		aris::core::Socket *sock_;
	};
}

#endif

