#include <gurobi_c++.h>  // 引入 Gurobi C++ API 头文件
#include <iostream>
#include <thread>
#include <vector>
#include "parser.h"

// 定义一个函数，用于加载并求解 MPS 文件
void solve_model(GRBModel& model, int num_thread = 1) {
    model.set(GRB_IntParam_Threads, num_thread);
    model.optimize();
    int solution_status = model.get(GRB_IntAttr_Status);
    if (solution_status == GRB_OPTIMAL) {
        double objval = model.get(GRB_DoubleAttr_ObjVal);
        std::cout << "Thread " << std::this_thread::get_id() << ": 目标值 = " << objval << std::endl;
    } 
}

std::vector<GRBModel> read_model(const Parser& args) {
    std::vector<GRBModel> model_list;
    for (size_t i = 0; i < args.input_path.size(); ++i) {
        try {
            // 创建一个新的环境
            GRBEnv env = GRBEnv(true);
            env.start();

            // 创建模型并从 MPS 文件加载
            model_list.push_back(GRBModel(env, args.input_path[i]));
        }

        catch (GRBException e) {
            std::cout << "Error Code " << e.getErrorCode() << std::endl;
            std::cout << e.getMessage() << std::endl;
        }
    }
    
    return model_list;
}

int main(int argc, char *argv[]) {
    
    Parser args = Parser(argc, argv);
    std::vector<GRBModel> model_list = read_model(args);

    // 创建一个 vector 来存储线程
    std::vector<std::thread> solver_threads;

     // 使用 lambda 捕获模型引用
    for (size_t i = 0; i < model_list.size(); ++i) {
        solver_threads.push_back(std::thread([&model_list, i]() {
            solve_model(model_list[i]);
        }));
    }

    // 等待所有线程完成
    for (auto& thr : solver_threads) {
        thr.join();
    }

    return 0;
}
