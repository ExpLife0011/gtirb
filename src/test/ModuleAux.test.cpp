#include <gtest/gtest.h>
#include <gtirb/Module.hpp>
#include <gtirb/ModuleAux.hpp>
#include <gtirb/NodeStructureError.hpp>
#include <memory>

TEST(Unit_ModuleAux, ctor_0)
{
    EXPECT_NO_THROW(gtirb::ModuleAux());
}

TEST(Unit_ModuleAux, validParent)
{
    auto module = std::make_unique<gtirb::Module>();
    auto ModuleAux = std::make_unique<gtirb::ModuleAux>();
    EXPECT_TRUE(ModuleAux->getIsValidParent(module.get()));
    EXPECT_TRUE(module->push_back(std::move(ModuleAux)));
}

TEST(Unit_ModuleAux, validParent_noException)
{
    auto module = std::make_unique<gtirb::Module>();
    auto ModuleAux = std::make_unique<gtirb::ModuleAux>();
    EXPECT_TRUE(ModuleAux->getIsValidParent(module.get()));
    EXPECT_NO_THROW(module->push_back(std::move(ModuleAux)));
}

TEST(Unit_ModuleAux, invalidParent)
{
    auto notAModule = std::make_unique<gtirb::Node>();
    auto ModuleAux = std::make_unique<gtirb::ModuleAux>();

    EXPECT_FALSE(ModuleAux->getIsValidParent(notAModule.get()));
    EXPECT_THROW(notAModule->push_back(std::move(ModuleAux)), gtirb::NodeStructureError);
}