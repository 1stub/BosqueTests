__CoreCpp::Nat main() noexcept  {
    std::vector<std::string> baseAssemblies = {
        "acc",
        "arith", 
        "cond",
        "inherit",
        "tt",
        "lambda",
        "meth",
        "ret",
        "slf"
    };
    
    std::vector<std::string> worklist;    
    for (int i = 0; i < 100'000; i++) {
        for (const std::string& assembly : baseAssemblies) {
            worklist.push_back(assembly);
        }
    }
    
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(worklist.begin(), worklist.end(), g);
    
    for (const auto& assemblyName : worklist) {
        if (assemblyName == "acc") {
            BSQAssembly::Assembly* explicitt = BSQAssembly::ExplicitifyTransformᘏprocess(BSQAssembly::acc());
            [[maybe_unused]] BSQAssembly::Assembly* simple = BSQAssembly::ConstantSimplificationᘏprocess(explicitt);
        }
        else if (assemblyName == "arith") {
            BSQAssembly::Assembly* explicitt = BSQAssembly::ExplicitifyTransformᘏprocess(BSQAssembly::arith());
            [[maybe_unused]] BSQAssembly::Assembly* simple = BSQAssembly::ConstantSimplificationᘏprocess(explicitt);
        }
        else if (assemblyName == "cond") {
            BSQAssembly::Assembly* explicitt = BSQAssembly::ExplicitifyTransformᘏprocess(BSQAssembly::cond());
            [[maybe_unused]] BSQAssembly::Assembly* simple = BSQAssembly::ConstantSimplificationᘏprocess(explicitt);
        }
        else if (assemblyName == "inherit") {
            BSQAssembly::Assembly* explicitt = BSQAssembly::ExplicitifyTransformᘏprocess(BSQAssembly::inherit());
            [[maybe_unused]] BSQAssembly::Assembly* simple = BSQAssembly::ConstantSimplificationᘏprocess(explicitt);
        }
        else if (assemblyName == "tt") {
            BSQAssembly::Assembly* explicitt = BSQAssembly::ExplicitifyTransformᘏprocess(BSQAssembly::tt());
            [[maybe_unused]] BSQAssembly::Assembly* simple = BSQAssembly::ConstantSimplificationᘏprocess(explicitt);
        }
        else if (assemblyName == "lambda") {
            BSQAssembly::Assembly* explicitt = BSQAssembly::ExplicitifyTransformᘏprocess(BSQAssembly::lambda());
            [[maybe_unused]] BSQAssembly::Assembly* simple = BSQAssembly::ConstantSimplificationᘏprocess(explicitt);
        }
        else if (assemblyName == "meth") {
            BSQAssembly::Assembly* explicitt = BSQAssembly::ExplicitifyTransformᘏprocess(BSQAssembly::meth());
            [[maybe_unused]] BSQAssembly::Assembly* simple = BSQAssembly::ConstantSimplificationᘏprocess(explicitt);
        }
        else if (assemblyName == "ret") {
            BSQAssembly::Assembly* explicitt = BSQAssembly::ExplicitifyTransformᘏprocess(BSQAssembly::ret());
            [[maybe_unused]] BSQAssembly::Assembly* simple = BSQAssembly::ConstantSimplificationᘏprocess(explicitt);
        }
        else if (assemblyName == "slf") {
            BSQAssembly::Assembly* explicitt = BSQAssembly::ExplicitifyTransformᘏprocess(BSQAssembly::slf());
            [[maybe_unused]] BSQAssembly::Assembly* simple = BSQAssembly::ConstantSimplificationᘏprocess(explicitt);
        }
    }
   
    MEM_STATS_DUMP(gtl_info);

    return 0_n;
}