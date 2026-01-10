# pragma once
#include <iostream>  // 对应 std::cout
#include <string>  // 对应 std::string
#include <memory>  // 对应 std::unique_ptr

// CompUnit  ::= FuncDef;

// FuncDef   ::= FuncType IDENT "(" ")" Block;
// FuncType  ::= "int";

// Block     ::= "{" Stmt "}";
// Stmt      ::= "return" Number ";";
// Number    ::= INT_CONST;

// 所有 AST 的基类
class BaseAST {
    public:
        virtual ~BaseAST() = default;

        virtual void Dump() const = 0;  // 纯虚函数, 用于打印 AST 结构
};

// CompUnit 是 BaseAST
class CompUnitAST : public BaseAST {
    public:
        // 用智能指针管理对象
        std::unique_ptr<BaseAST> func_def;

        void Dump() const override {
            // 打印 CompUnit 结构
            std::cout << "CompUnitAST {" << std::endl;
            if (func_def) {
                func_def->Dump();
            }
            std::cout << "}" << std::endl;
        }

};

// FuncDef 也是 BaseAST
// FuncDef ::= FuncType IDENT '(' ')' Block;
class FuncDefAST : public BaseAST {
    public:
        std::unique_ptr<BaseAST> func_type;
        std::string ident;
        std::unique_ptr<BaseAST> block;

        void Dump() const override {
            std::cout << "FuncDefAST {" << std::endl;
            if (func_type){
                func_type->Dump();
            }
            std::cout << ", " << ident << ", ";
            if (block) {
                block->Dump();
            }
            std::cout << "}" << std::endl;
        }
};

// FuncType
// FuncType  ::= "int";
class FuncTypeAST : public BaseAST {
    public:
        std::string type;  // 例如 "int"
        void Dump() const override {
            std::cout << "FuncTypeAST { type: " << type << " }" << std::endl;
        }
};

// Block     ::= "{" Stmt "}";
class BlockAST : public BaseAST {
    public:
        std::unique_ptr<BaseAST> stmts;
        void Dump() const override {
            std::cout << "BlockAST {" << std::endl;
            if (stmts) {
                stmts->Dump();
            }
            std::cout << "}" << std::endl;
        }
};

class StmtAST : public BaseAST {
    public:
        int number;
        void Dump() const override {
            // 自己负责打印 int
            std::cout << "StmtAST { return " << number << "; }"; 
        }
        

};





// ...


