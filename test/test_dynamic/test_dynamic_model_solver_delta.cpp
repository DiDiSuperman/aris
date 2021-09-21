﻿#include "test_dynamic_model_solver_delta.h"
#include <iostream>
#include <array>
#include <aris/dynamic/dynamic.hpp>

#include<type_traits>

using namespace aris::dynamic;

void test_model_solver_delta()
{

	////////////////////////////////////////////////测试建模/////////////////////////////////////////////////
	aris::dynamic::DeltaParam param;
	param.a = 0.5;
	param.b = 0.2;
	param.c = 0.1;
	param.d = 0.7;
	param.e = 0.1;

	aris::dynamic::DeltaModel m1(param);

	double pos[4]{ -0.1, 0.1, -0.45, 0.3 };
	m1.setOutputPos(pos);
	m1.inverseKinematics();

	double input[4];
	m1.getInputPos(input);
	dsp(1, 4, input);

	


	//dynamic_cast<aris::dynamic::GeneralMotion&>(m1->generalMotionPool().at(0)).setMpe(std::array<double, 6>{0.38453, 0, 0.6294, 0.0001, 0 + aris::PI/2, 0}.data(), "321");
	//m1->solverPool().at(0).kinPos();

	std::cout << "-----------------test model solver delta finished------------" << std::endl << std::endl;
}
