﻿#include <iostream>
#include <aris/core/core.hpp>
#include <aris/plan/plan.hpp>
#include <aris/robot/rokae.hpp>

using namespace aris::plan;

void test_move()
{
	const double error = 1e-10;
	
	const aris::Size size{ 150 };
	const double p1[size]{ 1.56,1.58495703841803,1.65982815367212,1.78461334576227,1.95931261468848,2.18392596045076,2.45845338304909,2.78289488248349,3.15725045875394,3.58152011186045,
		4.05570384180303,4.57980164858167,5.15381353219636,5.77773949264712,6.45157952993394,7.17533364405682,7.94900183501576,8.77258410281076,9.64608044744182,10.5694908689089,
		11.5428153672121,12.5410969039333,13.5393784406545,14.5376599773758,15.535941514097,16.5342230508182,17.5325045875394,18.5307861242606,19.5290676609818,20.527349197703,
		21.5256307344242,22.5239122711455,23.5221938078667,24.5204753445879,25.5187568813091,26.5170384180303,27.5153199547515,28.5136014914727,29.5118830281939,30.5101645649151,
		31.5084461016364,32.5067276383576,33.5050091750788,34.5032907118,35.5015722485212,36.4998537852424,37.4981353219636,38.4964168586849,39.4946983954061,40.4929799321273,
		41.4912614688485,42.4895430055697,43.4878245422909,44.4861060790121,45.4843876157333,46.4826691524545,47.4809506891758,48.479232225897,49.4775137626182,50.4757952993394,
		51.4740768360606,52.4723583727818,53.470639909503,54.4689214462242,55.4672029829455,56.4654845196667,57.4637660563879,58.4620475931091,59.4603291298303,60.4586106665515,
		61.4568922032727,62.4551737399939,63.4534552767152,64.4517368134364,65.4500183501576,66.4482998868788,67.4465814236,68.4448629603212,69.4431444970424,70.4414260337636,
		71.4397075704849,72.4379891072061,73.4362706439273,74.4345521806485,75.4328337173697,76.4311152540909,77.4293967908121,78.4276783275333,79.4259598642546,80.4242414009758,
		81.422522937697,82.4208044744182,83.4190860111394,84.4173675478606,85.4156490845818,86.413930621303,87.4122121580242,88.4104936947455,89.4087752314667,90.4070567681879,
		91.4053383049091,92.4036198416303,93.4019013783515,94.4001829150727,95.3984644517939,96.3967459885152,97.3950275252364,98.3933090619576,99.2668054065886,99.8907313670394,
		100.26508694331,100.3898721354,100.3898721354,100.3898721354,100.3898721354,100.3898721354,100.3898721354,100.3898721354,100.3898721354,100.3898721354,
		100.3898721354,100.3898721354,100.3898721354,100.3898721354,100.3898721354,100.3898721354,100.3898721354,100.3898721354,100.3898721354,100.3898721354,
		100.3898721354,100.3898721354,100.3898721354,100.3898721354,100.3898721354,100.3898721354,100.3898721354,100.3898721354,100.3898721354,100.3898721354,
		100.3898721354,100.3898721354,100.3898721354,100.3898721354,100.3898721354,100.3898721354,100.3898721354,100.3898721354,100.3898721354,100.3898721354,
	};
	const double v1[size]{ 0,0.0499140768360606,0.0998281536721212,0.149742230508182,0.199656307344242,0.249570384180303,0.299484461016364,0.349398537852424,0.399312614688485,0.449226691524546,
		0.499140768360606,0.549054845196667,0.598968922032727,0.648882998868788,0.698797075704849,0.748711152540909,0.79862522937697,0.84853930621303,0.898453383049091,0.948367459885152,
		0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,
		0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,
		0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,
		0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,
		0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,
		0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,
		0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,
		0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,
		0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.998281536721212,0.748711152540909,0.499140768360606,
		0.249570384180303,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
	};
	const double a1[size]{ 0.0499140768360606,0.0499140768360606,0.0499140768360606,0.0499140768360606,0.0499140768360606,0.0499140768360606,0.0499140768360606,0.0499140768360606,0.0499140768360606,0.0499140768360606,
		0.0499140768360606,0.0499140768360606,0.0499140768360606,0.0499140768360606,0.0499140768360606,0.0499140768360606,0.0499140768360606,0.0499140768360606,0.0499140768360606,0.0499140768360606,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0, -0.249570384180303, -0.249570384180303, -0.249570384180303,
		-0.249570384180303,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0 };
	const double p2[size]{ 1.56,1.53917340610843,1.47669362443373,1.3725606549759,1.22677449773494,1.03933515271084,0.810242619903615,0.539496899313253,0.227097990939759,-0.126954105216867,
		-0.522659389156626,-0.960017860879518,-1.48068270816867,-1.79308161654217,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,
		-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,
		-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,
		-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,
		-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,
		-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,
		-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,
		-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,
		-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,
		-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,
		-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,
		-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,
		-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,
		-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,-1.897214586,

	};
	const double v2[size]{ -0,-0.0416531877831325,-0.0833063755662651,-0.124959563349398,-0.16661275113253,-0.208265938915663,-0.249919126698795,-0.291572314481928,-0.33322550226506,-0.374878690048193,
		-0.416531877831325,-0.624797816746988,-0.416531877831325,-0.208265938915663,-0,-0,-0,-0,-0,-0,
		-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,
		-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,
		-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,
		-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,
		-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,
		-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,
		-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,
		-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,
		-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,
		-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,
		-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,
		-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,
		-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,
	};
	const double a2[size]{ -0.0416531877831325,-0.0416531877831325,-0.0416531877831325,-0.0416531877831325,-0.0416531877831325,-0.0416531877831325,-0.0416531877831325,-0.0416531877831325,-0.0416531877831325,-0.0416531877831325,
		-0.0416531877831325,0.208265938915663,0.208265938915663,0.208265938915663,-0,-0,-0,-0,-0,-0,
		-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,
		-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,
		-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,
		-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,
		-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,
		-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,
		-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,
		-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,
		-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,
		-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,
		-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,
		-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,
		-0,-0,-0,-0,-0,-0,-0,-0,-0,-0, };

	const double begin_p = 1.56;
	const double end_p1 = 100.3898721354;
	const double end_p2 = -1.897214586;
	const double vel = 10.0;
	const double acc = 5.0;
	const double dec = 25.0;
	const double frequence{ 10 };

	double result_p[size], result_v[size], result_a[size];
	aris::Size count;

	for (aris::Size i = 0; i < size; ++i)
	{
		aris::plan::moveAbsolute(static_cast<double>(i), begin_p, end_p1, vel / frequence, acc / frequence / frequence, dec / frequence / frequence, result_p[i], result_v[i], result_a[i], count);
	}
	if (!(aris::dynamic::s_is_equal(size, result_p, p1, error) && aris::dynamic::s_is_equal(size, result_v, v1, error) && aris::dynamic::s_is_equal(size, result_a, a1, error) && count == 111))std::cout << "\"moveAbsolute\" failed" << std::endl;
	for (aris::Size i = 0; i < size; ++i)
	{
		aris::plan::moveAbsolute(static_cast<double>(i), begin_p, end_p2, vel / frequence, acc / frequence / frequence, dec / frequence / frequence, result_p[i], result_v[i], result_a[i], count);
	}
	if (!(aris::dynamic::s_is_equal(size, result_p, p2, error) && aris::dynamic::s_is_equal(size, result_v, v2, error) && aris::dynamic::s_is_equal(size, result_a, a2, error) && count == 14))std::cout << "\"moveAbsolute\" failed" << std::endl;
}
void test_optimal()
{
	auto m = aris::robot::createModelRokaeXB4();

	aris::plan::OptimalTrajectory planner;

	std::vector<aris::plan::OptimalTrajectory::MotionLimit> limits(6, {1.0, -1.0, 10, -10, 100, -100, 100, -100});

	planner.setMotionLimit(limits);
	planner.setModel(m.get());
	planner.setSolver(dynamic_cast<aris::dynamic::InverseKinematicSolver*>(&m->solverPool()[0]));
	planner.setBeginNode(OptimalTrajectory::Node{ 0,0,0 });
	planner.setEndNode(OptimalTrajectory::Node{ 1,0,0 });
	planner.setFunction([](double s, double ds, std::vector<double> &pq, std::vector<double> &dpq_ds, std::vector<double> &ddpq_ds2)->void
	{
		double begin_pq[7]{ 0.398,0,0.6295,0,0.70710678118655,0,0.70710678118655 }, end_pq[7]{ 0.36,0.1,0.6295,0,0.70710678118655,0,0.70710678118655 };
		if (aris::dynamic::s_vv(4, begin_pq + 3, end_pq + 3) < 0) aris::dynamic::s_iv(4, begin_pq + 3);

		// pq = begin_pq * a + end_pq * b
		// dpq/ds = begin_pq * da/ds + end_pq * db/ds
		// ddpq/ds^2 = begin_pq * dda/ds^2 + end_pq * ddb/ds^2
		//
		// 对于位置来说:
		//   a = 1 - s       b = s
		//  da = -1         db = 1     
		// dda = 0         ddb = 0
		//
		// 对于角度球面插值，参考 https://www.cnblogs.com/21207-iHome/p/6952004.html：
		//   a = sin((1 - s)*theta) / sin(theta)                         b = sin(s*theta) / sin(theta);
		//  da = -cos((1 - s)*theta) / sin(theta) * theta               db = cos(s*theta) / sin(theta) * theta
		// dda = -sin((1 - s)*theta) / sin(theta) * theta * theta      ddb = -sin(s*theta) / sin(theta) * theta * theta
		// 
		// pq 和 vq可以直接求得：
		// pq = begin_pq * a + end_pq * b
		// vq = begin_pq * da * ds + end_pq * db * ds
		//
		// 于是 g 和 h为：
		// g = vq2vs(pq, dpq/ds)
		// h = aq2as(pq, vq, ddpq/ds^2)

		pq.resize(7);
		dpq_ds.resize(7);
		ddpq_ds2.resize(7);

		// 位置插值 //
		double a{ 1 - s }, b{ s }, da{ -1.0 }, db{ 1.0 }, dda{ 0.0 }, ddb{ 0.0 };
		aris::dynamic::s_vc(3, a, begin_pq, pq.data());
		aris::dynamic::s_va(3, b, end_pq, pq.data());
		aris::dynamic::s_vc(3, da, begin_pq, dpq_ds.data());
		aris::dynamic::s_va(3, db, end_pq, dpq_ds.data());
		aris::dynamic::s_vc(3, dda, begin_pq, ddpq_ds2.data());
		aris::dynamic::s_va(3, ddb, end_pq, ddpq_ds2.data());

		// 角度插值 //
		double c = aris::dynamic::s_vv(4, begin_pq + 3, end_pq + 3);	
		if (c < 0.999)
		{
			auto theta = std::acos(c);
			a = std::sin((1 - s)*theta) / std::sin(theta);
			b = std::sin(s*theta) / std::sin(theta);
			da = -theta * std::cos((1 - s)*theta) / std::sin(theta);
			db = theta * std::cos(s*theta) / std::sin(theta);
			dda = -std::sin((1 - s)*theta) / std::sin(theta) * theta * theta;
			ddb = -sin(s*theta) / sin(theta) * theta * theta;
		}

		aris::dynamic::s_vc(4, a, begin_pq + 3, pq.data() + 3);
		aris::dynamic::s_va(4, b, end_pq + 3, pq.data() + 3);
		aris::dynamic::s_vc(4, da, begin_pq + 3, dpq_ds.data() + 3);
		aris::dynamic::s_va(4, db, end_pq + 3, dpq_ds.data() + 3);
		aris::dynamic::s_vc(4, dda, begin_pq + 3, ddpq_ds2.data() + 3);
		aris::dynamic::s_va(4, ddb, end_pq + 3, ddpq_ds2.data() + 3);
	});
	planner.run();

	std::ofstream file;

	file.open("C:\\Users\\py033\\Desktop\\test.txt");
	file << std::setprecision(15);
	for (auto &node : planner.list_)
	{
		std::vector<double> pq, dpq_ds, ddpq_ds2;
		planner.plan(node.s, node.ds, pq, dpq_ds, ddpq_ds2);

		for (aris::Size i = 0; i < planner.model->generalMotionPool().size(); ++i){
			auto &gm = dynamic_cast<aris::dynamic::GeneralMotion&>(planner.model->generalMotionPool().at(i));

			double vs[6], as[6];
			aris::dynamic::s_aq2as(pq.data() + 7 * i, dpq_ds.data() + 7 * i, ddpq_ds2.data() + 7 * i, as, vs);

			double real_vs[6];
			aris::dynamic::s_vc(6, node.ds, vs, real_vs);

			gm.setMpq(pq.data() + 7 * i);
			gm.setMvs(real_vs);
		}

		planner.solver->kinPos();
		planner.solver->kinVel();
		planner.solver->cptJacobi();
		
		file << node.s << "  ";
		for (auto &mot : planner.model->motionPool())
		{
			mot.updP();
			file << mot.mp() << "  ";
		}
		file << "\n";
	}


	file.close();
}


void test_moveAbsolute2()
{
	//0.4, 0.00186295223741914, 1.86295223741914, 0.4, 0.10297442, 2.09439512, 0.400000931476119, 0, -1.86295223741914, 1
	double pt = 0.4000078;
	double vt = 0.0;
	double at = 0.0;
	double pa = 0.4;
	double va = 0.000231;
	double aa = 1.86295223741914;
	double vm = 0.10297442; // 295.0 / 360 * 2 * aris::PI * 0.02
	double am = 2.09439512; // 1500.0 / 360 * 2 * aris::PI *0.01

	aris::Size n = 1;
	//pa = 0.40000712223416;  va = 0;  aa = 1.35553167924087;
	//std::vector<double> p_vec, v_vec, a_vec;
	//p_vec.push_back(pa);
	//v_vec.push_back(va);
	//a_vec.push_back(aa);
	std::cout << std::setprecision(15) << "p:" << pa << "  v:" << va << "  a:" << aa << std::endl;
	while (n)
	{
		aris::Size t;
		n = aris::plan::moveAbsolute2(pa, va, aa, pt, vt, at, vm, am, am, 1e-3, 1e-10, pa, va, aa, t);

		//p_vec.push_back(pa);
		//v_vec.push_back(va);
		//a_vec.push_back(aa);

		std::cout <<std::setprecision(15) << "p:" << pa << "  v:" << va << "  a:" << aa << std::endl;
	}

	//n = 5;
	//while (--n)
	//{
	//	aris::Size t;
	//	aris::plan::moveAbsolute2(pa, va, aa, pt, vt, at, vm, am, am, 1e-3, 1e-10, pa, va, aa, t);

	//	//p_vec.push_back(pa);
	//	//v_vec.push_back(va);
	//	//a_vec.push_back(aa);

	//	std::cout << "p:" << pa << "  v:" << va << "  a:" << aa << std::endl;
	//}
}

void test_function()
{
	std::cout << std::endl << "-----------------test function---------------------" << std::endl;
	//test_optimal();
	test_moveAbsolute2();
	std::cout << "-----------------test function finished------------" << std::endl << std::endl;
}

