#include <string>
#include <iostream>
#include <functional>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <limits>

#include "aris_core_xml.h"

using namespace std;

namespace aris
{
	namespace core
	{
		// ��׼����ģ�� //
		/*
		template <class T, class A = std::allocator<T> >
		class X {
		public:
		typedef A allocator_type;
		typedef typename A::value_type value_type;
		typedef typename A::reference reference;
		typedef typename A::const_reference const_reference;
		typedef typename A::difference_type difference_type;
		typedef typename A::size_type size_type;

		class iterator {
		public:
		typedef typename A::difference_type difference_type;
		typedef typename A::value_type value_type;
		typedef typename A::reference reference;
		typedef typename A::pointer pointer;
		typedef std::random_access_iterator_tag iterator_category; //or another tag

		iterator();
		iterator(const iterator&);
		~iterator();

		auto operator=(const iterator&)->iterator&;
		auto operator==(const iterator&) const->bool;
		auto operator!=(const iterator&) const->bool;
		auto operator<(const iterator&) const->bool; //optional
		auto operator>(const iterator&) const->bool; //optional
		auto operator<=(const iterator&) const->bool; //optional
		auto operator>=(const iterator&) const->bool; //optional

		auto operator++()->iterator&;
		auto operator++(int)->iterator; //optional
		auto operator--()->iterator&; //optional
		auto operator--(int)->iterator; //optional
		auto operator+=(size_type)->iterator&; //optional
		auto operator+(size_type) const->iterator; //optional
		friend auto operator+(size_type, const iterator&)->iterator; //optional
		auto operator-=(size_type)->iterator&; //optional
		auto operator-(size_type) const->iterator; //optional
		auto operator-(iterator) const->difference_type; //optional

		auto operator*() const->reference;
		auto operator->() const->pointer;
		auto operator[](size_type) const->reference; //optional
		};
		class const_iterator {
		public:
		typedef typename A::difference_type difference_type;
		typedef typename A::value_type value_type;
		typedef typename A::const_reference const_reference;
		typedef typename A::const_pointer const_pointer;
		typedef std::random_access_iterator_tag iterator_category; //or another tag

		const_iterator();
		const_iterator(const const_iterator&);
		const_iterator(const iterator&);
		~const_iterator();

		auto operator=(const const_iterator&)->const_iterator&;
		auto operator==(const const_iterator&) const->bool;
		auto operator!=(const const_iterator&) const->bool;
		auto operator<(const const_iterator&) const->bool; //optional
		auto operator>(const const_iterator&) const->bool; //optional
		auto operator<=(const const_iterator&) const->bool; //optional
		auto operator>=(const const_iterator&) const->bool; //optional

		auto operator++()->const_iterator&;
		auto operator++(int)->const_iterator; //optional
		auto operator--()->const_iterator&; //optional
		auto operator--(int)->const_iterator; //optional
		auto operator+=(size_type)->const_iterator&; //optional
		auto operator+(size_type) const->const_iterator; //optional
		friend auto operator+(size_type, const const_iterator&)->const_iterator; //optional
		auto operator-=(size_type)->const_iterator&; //optional
		auto operator-(size_type) const->const_iterator; //optional
		auto operator-(const_iterator) const->difference_type; //optional

		auto operator*() const->const_reference;
		auto operator->() const->const_pointer;
		auto operator[](size_type) const->const_reference; //optional
		};

		typedef std::reverse_iterator<iterator> reverse_iterator; //optional
		typedef std::reverse_iterator<const_iterator> const_reverse_iterator; //optional

		X();
		X(const X&);
		~X();

		auto operator=(const X&)->X&;
		auto operator==(const X&) const->bool;
		auto operator!=(const X&) const->bool;
		auto operator<(const X&) const->bool; //optional
		auto operator>(const X&) const->bool; //optional
		auto operator<=(const X&) const->bool; //optional
		auto operator>=(const X&) const->bool; //optional

		auto begin()->iterator;
		auto begin() const->const_iterator;
		auto cbegin() const->const_iterator;
		auto end()->iterator;
		auto end() const->const_iterator;
		auto cend() const->const_iterator;
		auto rbegin()->reverse_iterator; //optional
		auto rbegin() const->const_reverse_iterator; //optional
		auto crbegin() const->const_reverse_iterator; //optional
		auto rend()->reverse_iterator; //optional
		auto rend() const->const_reverse_iterator; //optional
		auto crend() const->const_reverse_iterator; //optional

		auto front()->reference; //optional
		auto front() const->const_reference; //optional
		auto back()->reference; //optional
		auto back() const->const_reference; //optional
		template<class ...Args>
		auto emplace_front(Args...)->void; //optional
		template<class ...Args>
		auto emplace_back(Args...)->void; //optional
		auto push_front(const T&)->void; //optional
		auto push_front(T&&)->void; //optional
		auto push_back(const T&)->void; //optional
		auto push_back(T&&)->void; //optional
		auto pop_front()->void; //optional
		auto pop_back()->void; //optional
		auto operator[](size_type)->reference; //optional
		auto operator[](size_type) const->const_reference; //optional
		auto at(size_type)->reference; //optional
		auto at(size_type) const->const_reference; //optional

		template<class ...Args>
		auto emplace(const_iterator, Args...)->iterator; //optional
		auto insert(const_iterator, const T&)->iterator; //optional
		auto insert(const_iterator, T&&)->iterator; //optional
		auto insert(const_iterator, size_type, const T&)->iterator; //optional
		template<class iter>
		auto insert(const_iterator, iter, iter)->iterator; //optional
		auto insert(const_iterator, std::initializer_list<T>)->iterator; //optional
		auto erase(const_iterator)->iterator; //optional
		auto erase(const_iterator, const_iterator)->iterator; //optional
		auto clear()->void; //optional
		template<class iter>
		auto assign(iter, iter)->void; //optional
		auto assign(std::initializer_list<T>)->void; //optional
		auto assign(size_type, const T&)->void; //optional

		auto swap(X&)->void;
		auto size()->size_type;
		auto max_size()->size_type;
		auto empty()->bool;

		auto get_allocator()->A; //optional
		};
		template <class T, class A = std::allocator<T> >
		auto swap(X<T, A>&, X<T, A>&)->void; //optional
		*/
		
		template<> ImpPtr<Object>::ImpPtr(const ImpPtr &other) :data_unique_ptr_(other->root().childTypeMap().at(other->type()).newFromObject(*other)) {};
		template<> auto ImpPtr<Object>::operator=(const ImpPtr &other)->ImpPtr<Object>&
		{ 
			other->root().childTypeMap().at(other->type()).assign(*other, **this); 
			return *this;
		};
		template<> auto ImpPtr<Object>::operator=(ImpPtr &&other)noexcept ->ImpPtr<Object>&
		{ 
			other->root().childTypeMap().at(other->type()).assignR(std::move(*other), **this);
			return *this;
		};

		template<> auto ImpContainer<Object>::operator=(const ImpContainer& other)->ImpContainer<Object>&
		{
			if (size() != other.size())throw std::runtime_error("you must assign Object with same size");
			for (std::size_t i = 0; i < size(); ++i)other.at(i).root().childTypeMap().at(other.at(i).type()).assign(other.at(i), at(i));
			return *this;
		}
		template<> auto ImpContainer<Object>::operator=(ImpContainer&&other)->ImpContainer<Object>&
		{
			if (size() != other.size())throw std::runtime_error("you must assignR Object with same size");
			for (std::size_t i = 0; i < size(); ++i)other.at(i).root().childTypeMap().at(other.at(i).type()).assignR(std::move(other.at(i)), at(i));
			return *this;
		}

		struct Object::Imp 
		{
			Object *father_;
			std::size_t id_;
			std::string name_;
			std::string default_type_{ Object::Type() };
			std::map<std::string, std::shared_ptr<Object> > save_data_map_;

			Imp(Object *father, std::size_t id, const std::string &name) :father_(father), name_(name), id_(id), default_type_(Object::Type()) {}
			Imp(Object *father, std::size_t id, const aris::core::XmlElement &xml_ele) :father_(father), name_(xml_ele.name()), id_(id), default_type_(xml_ele.Attribute("default_child_type")? xml_ele.Attribute("default_child_type"): Object::Type()){}
			Imp(const Imp &other) = default;
			Imp(Imp &&other) = default;
			Imp &operator=(const Imp &) = default;
			Imp &operator=(Imp &&) = default;
		};
		struct Root::Imp
		{
			std::map<std::string, TypeInfo> type_map_{ std::make_pair(Object::Type(),TypeInfo::CreateTypeInfo<Object>()) };

			Imp() {}
			Imp(const Imp &other) {}
			Imp(Imp &&other) {}
			Imp &operator=(const Imp &) { return *this; }
			Imp &operator=(Imp &&) { return *this; }
		};

		auto Object::root()->Root& { return dynamic_cast<Root *>(this) ? dynamic_cast<Root &>(*this) : father().root(); }
		auto Object::root()const->const Root&{ return dynamic_cast<const Root *>(this) ? dynamic_cast<const Root &>(*this) : father().root(); }
		auto Object::saveXml(aris::core::XmlElement &xml_ele) const->void
		{ 
			xml_ele.DeleteChildren();
			xml_ele.SetName(name().c_str());
			xml_ele.SetAttribute("type", this->type().c_str());

			for (auto &ele : *this)
			{
				auto new_ele = xml_ele.GetDocument()->NewElement(ele.name().c_str());
				ele.saveXml(*new_ele);
				xml_ele.InsertEndChild(new_ele);
			}
		}
		auto Object::id()const->std::size_t { return imp_->id_; }
		auto Object::name() const->const std::string&{ return imp_->name_; }
		auto Object::father()->Object& { return *imp_->father_; }
		auto Object::father()const->const Object&{ return *imp_->father_; }
		auto Object::save(const std::string &name, bool auto_override_save)->void
		{
			decltype(imp_->save_data_map_) tem = std::move(imp_->save_data_map_);
			
			if ((!auto_override_save) && (tem.find(name) != tem.end()))
				throw std::runtime_error("Object \"" + this->name() + "\" already has a save named \"" + name + "\", can't save");

			auto save_content = std::shared_ptr<Object>(root().childTypeMap().find(this->type())->second.newFromObject(*this));
			tem.insert(std::make_pair(name, save_content));

			imp_->save_data_map_ = std::move(tem);
		}
		auto Object::load(const std::string &name, bool auto_delete_save)->void
		{
			decltype(imp_->save_data_map_) tem = std::move(imp_->save_data_map_);
			
			if (tem.find(name) == tem.end())
				throw std::runtime_error("Object \"" + this->name() + "\" does not has a save named \"" + name + "\", can't load");
			root().childTypeMap().find(this->type())->second.assign(*tem.at(name), std::ref(*this));
			if(auto_delete_save)tem.erase(name);

			imp_->save_data_map_ = std::move(tem);
		}
		auto Object::findByName(const std::string &name)->iterator
		{
			return std::find_if(this->begin(), this->end(), [&name, this](Object & p) {return (p.name() == name); });
		}
		auto Object::findByName(const std::string &name) const->const_iterator
		{
			return const_cast<Object *>(this)->findByName(name);
		}
		auto Object::add(const aris::core::XmlElement &xml_ele)->Object &
		{
			std::string type = xml_ele.Attribute("type") ? xml_ele.Attribute("type"): imp_->default_type_;

			if (root().imp_->type_map_.find(type) == root().imp_->type_map_.end())
			{
				throw std::runtime_error("unrecognized type \"" + type
					+ "\" when add xml element \"" + xml_ele.name() + "\" to \"" + name() + "\"");
			}
			else
			{
				push_back_ptr(root().imp_->type_map_.find(type)->second.newFromXml(*this, size(), xml_ele));
				return back();
			}
		}
		auto Object::add(const Object &object)->Object &
		{
			if (root().imp_->type_map_.find(object.type()) == root().imp_->type_map_.end())
			{
				throw std::runtime_error("unrecognized type \"" + object.type()	+ "\" when add object \"" + object.name() + "\" to \"" + name() + "\"");
			}
			else
			{
				push_back_ptr(root().imp_->type_map_.find(object.type())->second.newFromObject(object));
				back().imp_->id_ = size() - 1;
				back().imp_->name_ = object.name();
				back().imp_->father_ = this;

				return back();
			}
		}
		auto Object::add(Object &&object)->Object &
		{
			if (root().imp_->type_map_.find(object.type()) == root().imp_->type_map_.end())
			{
				throw std::runtime_error("unrecognized type \"" + object.type()	+ "\" when add object \"" + object.name() + "\" to \"" + name() + "\"");
			}
			else
			{
				push_back_ptr(root().imp_->type_map_.find(object.type())->second.newFromObjectR(std::move(object)));
				back().imp_->id_ = size() - 1;
				back().imp_->name_ = object.name();
				back().imp_->father_ = this;

				return back();
			}
		}
		auto Object::attributeBool(const aris::core::XmlElement &xml_ele, const std::string &attribute_name)const->bool
		{
			std::string error = "failed to get bool attribute \"" + attribute_name + "\" in \"" + type() + "\" \"" + name() + "\", because ";
			
			if (!xml_ele.Attribute(attribute_name.c_str()))
				throw std::runtime_error(error + "this attribute is not found in xml file");

			if (xml_ele.Attribute(attribute_name.c_str(), "true"))
			{
				return true;
			}
			else if (xml_ele.Attribute(attribute_name.c_str(), "false"))
			{
				return false;
			}
			else
			{
				throw std::runtime_error(error + "bool attribute must be \"true\" or \"false\", but the attribute text is \"" + xml_ele.Attribute(attribute_name.c_str()) + "\"");
			}
		}
		auto Object::attributeBool(const aris::core::XmlElement &xml_ele, const std::string &attribute_name, bool default_value)const->bool
		{
			if (!xml_ele.Attribute(attribute_name.c_str()))return default_value;
			else return attributeBool(xml_ele, attribute_name);
		}
		auto Object::attributeInt64(const aris::core::XmlElement &xml_ele, const std::string &attribute_name)const->std::int64_t
		{
			std::string error = "failed to get int64 attribute \"" + attribute_name + "\" in \"" + type() + "\" \"" + name() + "\", because ";
			
			if (!xml_ele.Attribute(attribute_name.c_str()))
				throw std::runtime_error(error + "this attribute is not found in xml file");

			try
			{
				return std::stoll(xml_ele.Attribute(attribute_name.c_str()), nullptr, 0);
			}
			catch (std::exception &e)
			{
				throw std::runtime_error(error + "attribute text \"" + xml_ele.Attribute(attribute_name.c_str()) + "\" is invalid:" + e.what());
			}
		}
		auto Object::attributeInt64(const aris::core::XmlElement &xml_ele, const std::string &attribute_name, std::int64_t default_value)const->std::int64_t
		{
			if (!xml_ele.Attribute(attribute_name.c_str()))return default_value;
			else return attributeInt64(xml_ele, attribute_name);
		}
		auto Object::attributeInt32(const aris::core::XmlElement &xml_ele, const std::string &attribute_name)const->std::int32_t
		{
			std::string error = "failed to get int32 attribute \"" + attribute_name + "\" in \"" + type() + "\" \"" + name() + "\", because ";

			if (!xml_ele.Attribute(attribute_name.c_str()))	throw std::runtime_error(error + "this attribute is not found in xml file");

			long long value_ll;
			try
			{
				value_ll = std::stoll(xml_ele.Attribute(attribute_name.c_str()), nullptr, 0);
			}
			catch (std::exception &e)
			{
				throw std::runtime_error(error + "attribute text \"" + xml_ele.Attribute(attribute_name.c_str()) + "\" is invalid:" + e.what());
			}

			if (value_ll > std::numeric_limits<std::int32_t>::max() || value_ll < std::numeric_limits<std::int32_t>::min())
				throw std::runtime_error(error + "attribute text \"" + xml_ele.Attribute(attribute_name.c_str()) + "\" is invalid: the value is out of range");

			return static_cast<std::int32_t>(value_ll);
		}
		auto Object::attributeInt32(const aris::core::XmlElement &xml_ele, const std::string &attribute_name, std::int32_t default_value)const->std::int32_t
		{
			if (!xml_ele.Attribute(attribute_name.c_str()))return default_value;
			else return attributeInt32(xml_ele, attribute_name);
		}
		auto Object::attributeInt16(const aris::core::XmlElement &xml_ele, const std::string &attribute_name)const->std::int16_t
		{
			std::string error = "failed to get int16 attribute \"" + attribute_name + "\" in \"" + type() + "\" \"" + name() + "\", because ";

			if (!xml_ele.Attribute(attribute_name.c_str()))	throw std::runtime_error(error + "this attribute is not found in xml file");

			long long value_ll;
			try
			{
				value_ll = std::stoll(xml_ele.Attribute(attribute_name.c_str()), nullptr, 0);
			}
			catch (std::exception &e)
			{
				throw std::runtime_error(error + "attribute text \"" + xml_ele.Attribute(attribute_name.c_str()) + "\" is invalid:" + e.what());
			}

			if (value_ll > std::numeric_limits<std::int16_t>::max() || value_ll < std::numeric_limits<std::int16_t>::min())
				throw std::runtime_error(error + "attribute text \"" + xml_ele.Attribute(attribute_name.c_str()) + "\" is invalid: the value is out of range");

			return static_cast<std::int16_t>(value_ll);
		}
		auto Object::attributeInt16(const aris::core::XmlElement &xml_ele, const std::string &attribute_name, std::int16_t default_value)const->std::int16_t
		{
			if (!xml_ele.Attribute(attribute_name.c_str()))return default_value;
			else return attributeInt16(xml_ele, attribute_name);
		}
		auto Object::attributeInt8(const aris::core::XmlElement &xml_ele, const std::string &attribute_name)const->std::int8_t
		{
			std::string error = "failed to get int16 attribute \"" + attribute_name + "\" in \"" + type() + "\" \"" + name() + "\", because ";

			if (!xml_ele.Attribute(attribute_name.c_str()))	throw std::runtime_error(error + "this attribute is not found in xml file");

			long long value_ll;
			try
			{
				value_ll = std::stoll(xml_ele.Attribute(attribute_name.c_str()), nullptr, 0);
			}
			catch (std::exception &e)
			{
				throw std::runtime_error(error + "attribute text \"" + xml_ele.Attribute(attribute_name.c_str()) + "\" is invalid:" + e.what());
			}

			if (value_ll > std::numeric_limits<std::int8_t>::max() || value_ll < std::numeric_limits<std::int8_t>::min())
				throw std::runtime_error(error + "attribute text \"" + xml_ele.Attribute(attribute_name.c_str()) + "\" is invalid: the value is out of range");

			return static_cast<std::int8_t>(value_ll);
		}
		auto Object::attributeInt8(const aris::core::XmlElement &xml_ele, const std::string &attribute_name, std::int8_t default_value)const->std::int8_t
		{
			if (!xml_ele.Attribute(attribute_name.c_str()))return default_value;
			else return attributeInt8(xml_ele, attribute_name);
		}
		auto Object::attributeUint64(const aris::core::XmlElement &xml_ele, const std::string &attribute_name)const->std::uint64_t
		{
			std::string error = "failed to get uint64 attribute \"" + attribute_name + "\" in \"" + type() + "\" \"" + name() + "\", because ";

			if (!xml_ele.Attribute(attribute_name.c_str()))
				throw std::runtime_error(error + "this attribute is not found in xml file");

			try
			{
				return std::stoull(xml_ele.Attribute(attribute_name.c_str()), nullptr, 0);
			}
			catch (std::exception &e)
			{
				throw std::runtime_error(error + "attribute text \"" + xml_ele.Attribute(attribute_name.c_str()) + "\" is invalid:" + e.what());
			}
		}
		auto Object::attributeUint64(const aris::core::XmlElement &xml_ele, const std::string &attribute_name, std::uint64_t default_value)const->std::uint64_t
		{
			if (!xml_ele.Attribute(attribute_name.c_str()))return default_value;
			else return attributeUint64(xml_ele, attribute_name);
		}
		auto Object::attributeUint32(const aris::core::XmlElement &xml_ele, const std::string &attribute_name)const->std::uint32_t
		{
			std::string error = "failed to get uint32 attribute \"" + attribute_name + "\" in \"" + type() + "\" \"" + name() + "\", because ";

			if (!xml_ele.Attribute(attribute_name.c_str()))	throw std::runtime_error(error + "this attribute is not found in xml file");

			unsigned long long value_ull;
			try
			{
				value_ull = std::stoll(xml_ele.Attribute(attribute_name.c_str()), nullptr, 0);
			}
			catch (std::exception &e)
			{
				throw std::runtime_error(error + "attribute text \"" + xml_ele.Attribute(attribute_name.c_str()) + "\" is invalid:" + e.what());
			}

			if (value_ull > std::numeric_limits<std::uint32_t>::max())
				throw std::runtime_error(error + "attribute text \"" + xml_ele.Attribute(attribute_name.c_str()) + "\" is invalid: the value is out of range");

			return static_cast<std::uint32_t>(value_ull);
		}
		auto Object::attributeUint32(const aris::core::XmlElement &xml_ele, const std::string &attribute_name, std::uint32_t default_value)const->std::uint32_t
		{
			if (!xml_ele.Attribute(attribute_name.c_str()))return default_value;
			else return attributeUint32(xml_ele, attribute_name);
		}
		auto Object::attributeUint16(const aris::core::XmlElement &xml_ele, const std::string &attribute_name)const->std::uint16_t
		{
			std::string error = "failed to get uint16 attribute \"" + attribute_name + "\" in \"" + type() + "\" \"" + name() + "\", because ";

			if (!xml_ele.Attribute(attribute_name.c_str()))	throw std::runtime_error(error + "this attribute is not found in xml file");

			unsigned long long value_ull;
			try
			{
				value_ull = std::stoll(xml_ele.Attribute(attribute_name.c_str()), nullptr, 0);
			}
			catch (std::exception &e)
			{
				throw std::runtime_error(error + "attribute text \"" + xml_ele.Attribute(attribute_name.c_str()) + "\" is invalid:" + e.what());
			}

			if (value_ull > std::numeric_limits<std::uint16_t>::max())
				throw std::runtime_error(error + "attribute text \"" + xml_ele.Attribute(attribute_name.c_str()) + "\" is invalid: the value is out of range");

			return static_cast<std::uint16_t>(value_ull);
		}
		auto Object::attributeUint16(const aris::core::XmlElement &xml_ele, const std::string &attribute_name, std::uint16_t default_value)const->std::uint16_t
		{
			if (!xml_ele.Attribute(attribute_name.c_str()))return default_value;
			else return attributeUint16(xml_ele, attribute_name);
		}
		auto Object::attributeUint8(const aris::core::XmlElement &xml_ele, const std::string &attribute_name)const->std::uint8_t
		{
			std::string error = "failed to get uint8 attribute \"" + attribute_name + "\" in \"" + type() + "\" \"" + name() + "\", because ";

			if (!xml_ele.Attribute(attribute_name.c_str()))	throw std::runtime_error(error + "this attribute is not found in xml file");

			unsigned long long value_ull;
			try
			{
				value_ull = std::stoll(xml_ele.Attribute(attribute_name.c_str()), nullptr, 0);
			}
			catch (std::exception &e)
			{
				throw std::runtime_error(error + "attribute text \"" + xml_ele.Attribute(attribute_name.c_str()) + "\" is invalid:" + e.what());
			}

			if (value_ull > std::numeric_limits<std::uint8_t>::max())
				throw std::runtime_error(error + "attribute text \"" + xml_ele.Attribute(attribute_name.c_str()) + "\" is invalid: the value is out of range");

			return static_cast<std::uint8_t>(value_ull);
		}
		auto Object::attributeUint8(const aris::core::XmlElement &xml_ele, const std::string &attribute_name, std::uint8_t default_value)const->std::uint8_t
		{
			if (!xml_ele.Attribute(attribute_name.c_str()))return default_value;
			else return attributeUint8(xml_ele, attribute_name);
		}
		auto Object::attributeFloat(const aris::core::XmlElement &xml_ele, const std::string &attribute_name)const->float
		{
			std::string error = "failed to get double attribute \"" + attribute_name + "\" in \"" + type() + "\" \"" + name() + "\", because ";

			if (!xml_ele.Attribute(attribute_name.c_str()))
				throw std::runtime_error(error + "this attribute is not found in xml file");

			try
			{
				return std::stof(xml_ele.Attribute(attribute_name.c_str()));
			}
			catch (std::exception &e)
			{
				throw std::runtime_error(error + "attribute text \"" + xml_ele.Attribute(attribute_name.c_str()) + "\" is invalid:" + e.what());
			}
		}
		auto Object::attributeFloat(const aris::core::XmlElement &xml_ele, const std::string &attribute_name, float default_value)const->float
		{
			if (!xml_ele.Attribute(attribute_name.c_str()))return default_value;
			else return attributeFloat(xml_ele, attribute_name);
		}
		auto Object::attributeDouble(const aris::core::XmlElement &xml_ele, const std::string &attribute_name)const->double
		{
			std::string error = "failed to get double attribute \"" + attribute_name + "\" in \"" + type() + "\" \"" + name() + "\", because ";

			if (!xml_ele.Attribute(attribute_name.c_str()))
				throw std::runtime_error(error + "this attribute is not found in xml file");

			try
			{
				return std::stod(xml_ele.Attribute(attribute_name.c_str()));
			}
			catch (std::exception &e)
			{
				throw std::runtime_error(error + "attribute text \"" + xml_ele.Attribute(attribute_name.c_str()) + "\" is invalid:" + e.what());
			}
		}
		auto Object::attributeDouble(const aris::core::XmlElement &xml_ele, const std::string &attribute_name, double default_value)const->double
		{
			if (!xml_ele.Attribute(attribute_name.c_str()))return default_value;
			else return attributeDouble(xml_ele, attribute_name);
		}
		auto Object::attributeString(const aris::core::XmlElement &xml_ele, const std::string &attribute_name)const->std::string
		{
			std::string error = "failed to get string attribute \"" + attribute_name + "\" in \"" + type() + "\" \"" + name() + "\", because ";

			if (!xml_ele.Attribute(attribute_name.c_str()))
				throw std::runtime_error(error + "this attribute is not found in xml file");

			return xml_ele.Attribute(attribute_name.c_str());
		}
		auto Object::attributeString(const aris::core::XmlElement &xml_ele, const std::string &attribute_name, const std::string &default_value)const->std::string
		{
			return xml_ele.Attribute(attribute_name.c_str()) ? attributeString(xml_ele, attribute_name) : default_value;
		}
		auto Object::attributeChar(const aris::core::XmlElement &xml_ele, const std::string &attribute_name)const->char
		{
			std::string error = "failed to get char attribute \"" + attribute_name + "\" in \"" + type() + "\" \"" + name() + "\", because ";

			if (!xml_ele.Attribute(attribute_name.c_str()))
				throw std::runtime_error(error + "this attribute is not found in xml file");

			if (xml_ele.Attribute(attribute_name.c_str())[1]!=0)
				throw std::runtime_error(error + "this attribute string length is not 1");

			return xml_ele.Attribute(attribute_name.c_str())[0];
		}
		auto Object::attributeChar(const aris::core::XmlElement &xml_ele, const std::string &attribute_name, char default_value)const->char
		{
			return xml_ele.Attribute(attribute_name.c_str()) ? attributeChar(xml_ele, attribute_name) : default_value;
		}
		auto Object::operator=(const Object &other)->Object &
		{
			Object *father = imp_->father_;
			std::size_t id = imp_->id_;

			imp_ = other.imp_;
			ImpContainer::operator=(other);

			imp_->father_ = father;
			imp_->id_ = id;

			for (std::size_t i = 0; i < size(); ++i)
			{
				at(i).imp_->id_ = i;
				at(i).imp_->father_ = this;
			}

			return *this;
		}
		auto Object::operator=(Object &&other)->Object &
		{
			Object *father = imp_->father_;
			std::size_t id = imp_->id_;

			imp_ = std::move(other.imp_);
			ImpContainer::operator=(std::move(other));

			imp_->father_ = father;
			imp_->id_ = id;

			for (std::size_t i = 0; i < size(); ++i)
			{
				at(i).imp_->id_ = i;
				at(i).imp_->father_ = this;
			}

			return *this;
		}
		Object::~Object() {}
		Object::Object(const Object &other) :ImpContainer(other), imp_(other.imp_) { for (auto &child : *this)child.imp_->father_ = this; }
		Object::Object(Object &&other) : ImpContainer(std::move(other)), imp_(std::move(other.imp_)) { for (auto &child : *this)child.imp_->father_ = this; }
		Object::Object(Object &father, std::size_t id, const std::string &name) : imp_(new Imp(&father, id, name)) {}
		Object::Object(Object &father, std::size_t id, const aris::core::XmlElement &xml_ele) :imp_(new Imp(&father, id, xml_ele))
		{
			for (auto ele = xml_ele.FirstChildElement(); ele; ele = ele->NextSiblingElement())add(*ele);
		}

		auto Root::TypeInfo::alignChildID(Object &father, Object &child, std::size_t id)->void
		{
			child.imp_->id_ = id;
			child.imp_->father_ = &father;
		}
		auto Root::TypeInfo::registerTo(const std::string &type, Root &root)->void
		{
			root.imp_->type_map_.insert(std::make_pair(type, *this));
		}
		auto Root::childTypeMap()const ->const std::map<std::string, TypeInfo>&{return imp_->type_map_;	}
		auto Root::loadXml(const std::string &filename)->void
		{
			aris::core::XmlDocument xmlDoc;

			if (xmlDoc.LoadFile(filename.c_str()) != 0)
			{
				throw std::runtime_error((std::string("could not open file:") + std::string(filename)));
			}

			loadXml(xmlDoc);
		}
		auto Root::loadXml(const aris::core::XmlDocument &xml_doc)->void
		{
			loadXml(*xml_doc.RootElement());
		}
		auto Root::loadXml(const aris::core::XmlElement &xml_ele)->void
		{
			clear();
			for (auto ele = xml_ele.FirstChildElement(); ele; ele = ele->NextSiblingElement())add(*ele);
		}
		auto Root::saveXml(const std::string &filename) const->void
		{
			aris::core::XmlDocument doc;

			saveXml(doc);

			doc.SaveFile(filename.c_str());
		}
		auto Root::saveXml(aris::core::XmlDocument &xml_doc)const->void
		{
			xml_doc.DeleteChildren();

			auto header_xml_ele = xml_doc.NewDeclaration("xml version=\"1.0\" encoding=\"UTF-8\" ");
			xml_doc.InsertEndChild(header_xml_ele);

			auto root_xml_ele = xml_doc.NewElement(this->name().c_str());
			xml_doc.InsertEndChild(root_xml_ele);

			saveXml(*root_xml_ele);
		}
		Root::~Root() {}
		Root::Root(const std::string &name) :Object(*this, 0, name) {}
		Root::Root(const aris::core::XmlElement &xml_ele) :Object(*this, 0, xml_ele) {}

	}
}