    class BenchmarkTimer {
        private:
            std::chrono::high_resolution_clock::time_point start_time;
            double duration_ms = 0.0;
        
        public:
            BenchmarkTimer(): start_time{} {}; 
            inline void start() {
                start_time = std::chrono::high_resolution_clock::now();
            }
            
            inline void stop() {
                auto end = std::chrono::high_resolution_clock::now();
                duration_ms += std::chrono::duration_cast<
                    std::chrono::duration<double, std::milli>>(end - start_time).count();
            }
            
            double get_duration_ms() const { return duration_ms; }
            void reset() { duration_ms = 0.0; }
    };

    //
    // Do NOT change this! it will break the reproducibility of our experiemnts
    //
    constexpr uint32_t BENCHMARK_RANDOM_SEED = 0xDEADBEEF;

    //
    // Now these can change!
    //
    constexpr size_t DEFAULT_WORKLIST_SIZE = 600ULL;

    constexpr size_t NBODY_WORKLIST_SIZE = DEFAULT_WORKLIST_SIZE;
    constexpr size_t MIN_NBODY_STEPS = 50'500UL;
    constexpr size_t MAX_NBODY_STEPS = 50'500UL;

    constexpr size_t DB_WORKLIST_SIZE = DEFAULT_WORKLIST_SIZE;
    constexpr size_t MIN_DB_STEPS = 8'000UL;
    constexpr size_t MAX_DB_STEPS = 8'000UL;
    constexpr size_t NUM_DB_OPS = 10UL;

    constexpr size_t RAYTRACE_WORKLIST_SIZE = DEFAULT_WORKLIST_SIZE;
    constexpr size_t MIN_RAYTRACE_STEPS = 80'000UL;
    constexpr size_t MAX_RAYTRACE_STEPS = 80'000UL;
    constexpr size_t RAYTRACE_WIN_WIDTH = 1920UL;
    constexpr size_t RAYTRACE_WIN_HEIGHT = 1080UL;

    enum class OpType {
        NBODY = 1,
        DB,
        RAYTRACE
    };

    struct MixedOp {
        OpType type;
        size_t nbodywork;
        std::vector<size_t> dbbatch;
        std::vector<std::pair<size_t, size_t>> raybatch;
    };
    
    // Timing structure for individual operations
    struct OpTiming {
        double time;
        OpType type;
    };

    std::vector<OpTiming> op_timings; // Global to store timing data

    std::vector<std::vector<size_t>> dbworklist_create(std::mt19937& gen) {
        std::uniform_int_distribution<size_t> ops_dist(1, NUM_DB_OPS); 
        std::uniform_int_distribution<size_t> steps_dist(MIN_DB_STEPS, MAX_DB_STEPS); 

        std::vector<std::vector<size_t>> worklist;
        worklist.reserve(DB_WORKLIST_SIZE);

        for (size_t i = 0; i < DB_WORKLIST_SIZE; ++i) { 
            size_t numops = steps_dist(gen);
            std::vector<size_t> ops;
            ops.reserve(numops);
            for(size_t j = 0; j < numops; j++) {
                ops.push_back(ops_dist(gen));
            }
            worklist.push_back(ops);
        }

        return worklist;
    } 
    inline void db_bench(std::vector<size_t>& ops) noexcept {
        auto start = std::chrono::high_resolution_clock::now();

        Core::CString tmp { 0 };
       
        for(size_t& op : ops) {
            switch(op) {
                case 1:  tmp = testOpOnSample(DatabaseOperation{ &NumRecordsOp𝐓𝐲𝐩𝐞 }); break;
                case 2:  tmp = testOpOnSample(DatabaseOperation{ &EndOp𝐓𝐲𝐩𝐞 }); break;
                case 3:  tmp = testOpOnSample(DatabaseOperation{ &ListOp𝐓𝐲𝐩𝐞 }); break;
                case 4:  tmp = testOpOnSample(DatabaseOperation{ &GotoRecordOp𝐓𝐲𝐩𝐞, GotoRecordOp{ 2_n } }); break;
                case 5:  tmp = testOpOnSample(DatabaseOperation{ &NextOp𝐓𝐲𝐩𝐞 }); break;
                case 6:  tmp = testOpOnSample(DatabaseOperation{ &PreviousOp𝐓𝐲𝐩𝐞 }); break;
                case 7:  tmp = testOpOnSample(DatabaseOperation{ &StatusOp𝐓𝐲𝐩𝐞 }); break;
                case 8:  tmp = testOpOnSample(DatabaseOperation{ &AddOp𝐓𝐲𝐩𝐞, 𝐀𝐥𝐥𝐨𝐜𝐓𝐲𝐩𝐞( AddOp, alloc1, &AddOp𝐓𝐲𝐩𝐞, (AddOp{ 𝐀𝐥𝐥𝐨𝐜𝐓𝐲𝐩𝐞( Entry, alloc4, &Entry𝐓𝐲𝐩𝐞, (Entry{ Core::ListOps::s_list_create_3ᐸCStringᐳ([]() -> Core::CRope { const __CoreCpp::CChar* str = reinterpret_cast<const __CoreCpp::CChar*>("Bosque"); return Core::CRopeOps::s_crope_create(__CoreCpp::cbufferFromStringLiteral(0, 6, str)); }(), []() -> Core::CRope { const __CoreCpp::CChar* str = reinterpret_cast<const __CoreCpp::CChar*>("Yes"); return Core::CRopeOps::s_crope_create(__CoreCpp::cbufferFromStringLiteral(0, 3, str)); }(), []() -> Core::CRope { const __CoreCpp::CChar* str = reinterpret_cast<const __CoreCpp::CChar*>("Hybrid"); return Core::CRopeOps::s_crope_create(__CoreCpp::cbufferFromStringLiteral(0, 6, str)); }()) }) ) }) ) }); break;
                case 9:  tmp = testOpOnSample(DatabaseOperation{ &ModifyOp𝐓𝐲𝐩𝐞, 𝐀𝐥𝐥𝐨𝐜𝐓𝐲𝐩𝐞( ModifyOp, alloc1, &ModifyOp𝐓𝐲𝐩𝐞, (ModifyOp{ 𝐀𝐥𝐥𝐨𝐜𝐓𝐲𝐩𝐞( Entry, alloc4, &Entry𝐓𝐲𝐩𝐞, (Entry{ Core::ListOps::s_list_create_3ᐸCStringᐳ([]() -> Core::CRope { const __CoreCpp::CChar* str = reinterpret_cast<const __CoreCpp::CChar*>("Bosque"); return Core::CRopeOps::s_crope_create(__CoreCpp::cbufferFromStringLiteral(0, 6, str)); }(), []() -> Core::CRope { const __CoreCpp::CChar* str = reinterpret_cast<const __CoreCpp::CChar*>("Yes"); return Core::CRopeOps::s_crope_create(__CoreCpp::cbufferFromStringLiteral(0, 3, str)); }(), []() -> Core::CRope { const __CoreCpp::CChar* str = reinterpret_cast<const __CoreCpp::CChar*>("Hybrid"); return Core::CRopeOps::s_crope_create(__CoreCpp::cbufferFromStringLiteral(0, 6, str)); }()) }) ) }) ) }); break;
                case 10: tmp = testOpOnSample(DatabaseOperation{ &RemoveOp𝐓𝐲𝐩𝐞 }); break;
                default: {
                    std::cout << "value does not correspond to an existing db operation! - " << op << std::endl;
                    return ;
                }
            }
        }

        auto end = std::chrono::high_resolution_clock::now();
        double duration = std::chrono::duration<double, std::milli>(end - start).count();
        op_timings.push_back({duration, OpType::DB});
    }
    void db_run(std::vector<std::vector<size_t>>& worklist) noexcept { 
        BenchmarkTimer timer;
        timer.start();
        
        for(std::vector<size_t>& e : worklist) {
            db_bench(e);
        }
        timer.stop();
    
        std::cout << "db time: " << timer.get_duration_ms() / 1000 << " seconds" << std::endl;
        std::cout << "db memstats: " << std::endl;
        MEM_STATS_DUMP(gtl_info);
    }

    std::vector<std::vector<std::pair<size_t, size_t>>> raytraceworklist_create(std::mt19937& gen) {
        std::uniform_int_distribution<size_t> steps_dist(MIN_RAYTRACE_STEPS, MAX_RAYTRACE_STEPS);
        std::uniform_int_distribution<size_t> x_dist(0, RAYTRACE_WIN_WIDTH - 1);
        std::uniform_int_distribution<size_t> y_dist(0, RAYTRACE_WIN_HEIGHT - 1);
        
        std::vector<std::vector<std::pair<size_t, size_t>>> worklist;
        worklist.reserve(RAYTRACE_WORKLIST_SIZE);
    
        for (size_t i = 0; i < RAYTRACE_WORKLIST_SIZE; ++i) {
            size_t num_pixels = steps_dist(gen);
            std::vector<std::pair<size_t, size_t>> pixels;
            pixels.reserve(num_pixels);
            
            for (size_t j = 0; j < num_pixels; j++) {
                if (j < num_pixels * 0.4) {
                    pixels.push_back({x_dist(gen), y_dist(gen)});
                }
                else if (j < num_pixels * 0.8) {
                    std::uniform_int_distribution<size_t> center_x_dist(800, 1120);
                    std::uniform_int_distribution<size_t> center_y_dist(440, 640);
                    pixels.push_back({center_x_dist(gen), center_y_dist(gen)});
                }
                else {
                    if (j % 4 == 0) {
                        pixels.push_back({0, 0});
                    }
                    else if (j % 4 == 1) {
                        pixels.push_back({RAYTRACE_WIN_WIDTH - 1, 0});
                    }
                    else if (j % 4 == 2) {
                        pixels.push_back({0, RAYTRACE_WIN_HEIGHT - 1});
                    }
                    else {
                        pixels.push_back({RAYTRACE_WIN_WIDTH - 1, RAYTRACE_WIN_HEIGHT - 1});
                    }
                }
            }
            worklist.push_back(pixels);
        }
        
        return worklist;
    }
    
    inline void raytrace_bench(std::vector<std::pair<size_t, size_t>>& pixels) noexcept {
        auto start = std::chrono::high_resolution_clock::now();

        for (auto& pixel : pixels) {
            render_pixel(TO_BOSQUE_FLOAT(pixel.first), TO_BOSQUE_FLOAT(pixel.second), 
                        TO_BOSQUE_FLOAT(RAYTRACE_WIN_WIDTH), TO_BOSQUE_FLOAT(RAYTRACE_WIN_HEIGHT));
        }

        auto end = std::chrono::high_resolution_clock::now();
        double duration = std::chrono::duration<double, std::milli>(end - start).count();
        op_timings.push_back({duration, OpType::RAYTRACE});
    }    
    void raytrace_run(std::vector<std::vector<std::pair<size_t, size_t>>>& worklist) noexcept {
        BenchmarkTimer timer;
        timer.start();
    
        for (auto& pixel_batch : worklist) {
            raytrace_bench(pixel_batch);
        }
        timer.stop();
    
        std::cout << "raytrace time: " << timer.get_duration_ms() / 1000 << " seconds" << std::endl;
        std::cout << "raytrace memstats: " << std::endl;
        MEM_STATS_DUMP(gtl_info);
    }
    
    std::vector<size_t> nbodyworklist_create(std::mt19937& gen) { 
        std::uniform_int_distribution<size_t> dist(MIN_NBODY_STEPS, MAX_NBODY_STEPS);

        std::vector<size_t> worklist;
        worklist.reserve(NBODY_WORKLIST_SIZE);
        for(size_t i = 0; i < NBODY_WORKLIST_SIZE; i++) {
            worklist.push_back(dist(gen));
        }

        return worklist;
    }
    inline void nbody_bench(size_t& steps) noexcept {
        auto start = std::chrono::high_resolution_clock::now();

        NBodySystem* system = NBodySystemᘏcreate();
        for(size_t i = 0; i < steps; i++) {
            system = NBodySystemᘏadvance(system, step());
        }

        auto end = std::chrono::high_resolution_clock::now();
        double duration = std::chrono::duration<double, std::milli>(end - start).count();
        op_timings.push_back({duration, OpType::NBODY});
    }
    void nbody_run(const std::vector<size_t>& worklist) noexcept  {
        BenchmarkTimer timer;
        timer.start();
    
        for(size_t e : worklist) {
            nbody_bench(e);
        }
        timer.stop();
    
        std::cout << "nbody time: " << timer.get_duration_ms() / 1000 << " seconds" << std::endl;
        std::cout << "nbody memstats: " << std::endl;
        MEM_STATS_DUMP(gtl_info);
    }

    std::vector<MixedOp> mixedworklist_create(std::mt19937& gen) {        
        std::vector<size_t> nbody_worklist                                    = nbodyworklist_create(gen);
        std::vector<std::vector<size_t>> db_worklist                          = dbworklist_create(gen);
        std::vector<std::vector<std::pair<size_t, size_t>>> raytrace_worklist = raytraceworklist_create(gen);

        std::vector<MixedOp> shuffled_workloads;
        for(size_t& op : nbody_worklist) {
            shuffled_workloads.push_back(MixedOp{ OpType::NBODY, op, {}, {} });
        }
        for(std::vector<size_t>& opbatch : db_worklist) {
            shuffled_workloads.push_back(MixedOp{ OpType::DB, {}, opbatch, {} });
        }
        for(std::vector<std::pair<size_t, size_t>>& pixelbatch : raytrace_worklist) {
            shuffled_workloads.push_back(MixedOp{ OpType::RAYTRACE, {}, {}, pixelbatch });
        }

        std::shuffle(shuffled_workloads.begin(), shuffled_workloads.end(), gen);

        return shuffled_workloads;
    }
    void mixed_run(std::vector<MixedOp>& worklist) noexcept { 
        BenchmarkTimer timer;
        timer.start();
    
        int i = 0;
        for(MixedOp& e : worklist) {
            std::cout << i++ << std::endl;
            switch(e.type) {
                case OpType::NBODY:    nbody_bench(e.nbodywork); break;
                case OpType::DB:       db_bench(e.dbbatch); break;
                case OpType::RAYTRACE: raytrace_bench(e.raybatch); break;
                default: {
                    std::cout << "Unsupported op type!" << std::endl;
                    return;
                }
            }
        }
        timer.stop();
    
        std::cout << "mixed time: " << timer.get_duration_ms() / 1000 << " seconds" << std::endl;
        std::cout << "mixed memstats: " << std::endl;
        MEM_STATS_DUMP(gtl_info);
    }

    void calculate_and_print_timing_stats() {
        std::map<OpType, std::vector<double>> timings_by_type;
        
        for (const auto& timing : op_timings) {
            timings_by_type[timing.type].push_back(timing.time);
        }
        
        for (const auto& [op_type, times] : timings_by_type) {
            if (times.empty()) {
                continue;
            }
            
            double sum = 0.0, sum_sq = 0.0;
            double min_time = std::numeric_limits<double>::max();
            double max_time = std::numeric_limits<double>::min();
            
            for (double t : times) {
                sum += t;
                sum_sq += t * t;
                min_time = std::min(min_time, t);
                max_time = std::max(max_time, t);
            }
            
            double size = static_cast<double>(times.size());
            double mean = sum / size;
            double variance = (sum_sq - (sum * sum) / size) / (size - 1.0);
            double stdev = std::sqrt(variance);
            
            // Calculate percentiles
            std::vector<double> sorted_times = times;
            std::sort(sorted_times.begin(), sorted_times.end());
            
            auto get_percentile = [&](double percentile) {
                size_t index = static_cast<size_t>(sorted_times.size() * percentile);
                index = std::min(index, sorted_times.size() - 1);
                return sorted_times[index];
            };
            
            double p50 = get_percentile(0.50);  // 50th percentile (median)
            double p95 = get_percentile(0.95);  // 95th percentile
            double p99 = get_percentile(0.99);  // 99th percentile
            
            // Print comprehensive statistics
            std::string op_name;
            switch (op_type) {
                case OpType::NBODY: op_name = "nbody"; break;
                case OpType::DB: op_name = "db"; break;
                case OpType::RAYTRACE: op_name = "raytrace"; break;
                default: op_name = "unknown"; break;
            }
            
            std::cout << "===" << op_name << " Timing Statistics ===" << std::endl;
            std::cout << "Samples: " << times.size() << std::endl;
            std::cout << std::fixed << std::setprecision(6); // Full decimal precision
            std::cout << "Average: " << mean << " ms" << std::endl;
            std::cout << "Std Dev: " << stdev << " ms" << std::endl;
            std::cout << "50th %ile: " << p50 << " ms" << std::endl;
            std::cout << "95th %ile: " << p95 << " ms" << std::endl;
            std::cout << "99th %ile: " << p99 << " ms" << std::endl;
            std::cout << "Max: " << max_time << " ms" << std::endl;
            std::cout << "Min: " << min_time << " ms" << std::endl;
            std::cout.unsetf(std::ios_base::floatfield); // Reset formatting
            std::cout << std::setprecision(6); // Reset to default precision
        }
    }

    void calculate_and_print_server_stats() {
        if (op_timings.empty()) {
            return;
        }
        
        std::vector<double> all_times;
        all_times.reserve(op_timings.size());
        for (const auto& timing : op_timings ) {
            all_times.push_back(timing.time);
        }
        
        double sum = 0.0, sum_sq = 0.0;
        double min_time = std::numeric_limits<double>::max();
        double max_time = std::numeric_limits<double>::min();
        
        for (double t : all_times) {
            sum += t;
            sum_sq += t * t;
            min_time = std::min(min_time, t);
            max_time = std::max(max_time, t);
        }
        
        double size = static_cast<double>(all_times.size());
        double mean = sum / size;
        double variance = (sum_sq - (sum * sum) / size) / (size - 1.0);
        double stdev = std::sqrt(variance);
        
        std::vector<double> sorted_times = all_times;
        std::sort(sorted_times.begin(), sorted_times.end());
        
        auto get_percentile = [&](double percentile) {
            size_t index = static_cast<size_t>(sorted_times.size() * percentile);
            index = std::min(index, sorted_times.size() - 1);
            return sorted_times[index];
        };
        
        double p50 = get_percentile(0.50);
        double p95 = get_percentile(0.95);
        double p99 = get_percentile(0.99);
        
        std::cout << "=== SERVER-WIDE Timing Statistics ===" << std::endl;
        std::cout << "Total operations: " << all_times.size() << std::endl;
        std::cout << std::fixed << std::setprecision(6); // Full decimal precision
        std::cout << "Average per operation: " << mean << " ms" << std::endl;
        std::cout << "Std Dev per operation: " << stdev << " ms" << std::endl;
        std::cout << "50th %ile: " << p50 << " ms" << std::endl;
        std::cout << "95th %ile: " << p95 << " ms" << std::endl;
        std::cout << "99th %ile: " << p99 << " ms" << std::endl;
        std::cout << "Max operation time: " << max_time << " ms" << std::endl;
        std::cout << "Min operation time: " << min_time << " ms" << std::endl;
        
        double total_time = std::accumulate(all_times.begin(), all_times.end(), 0.0);
        std::cout << "Total server time: " << total_time << " ms" << std::endl;
        std::cout.unsetf(std::ios_base::floatfield); // Reset formatting
        std::cout << std::setprecision(6); // Reset to default precision
    }
    
    __CoreCpp::Nat main() noexcept  {
        std::random_device rd{};
        std::mt19937 gen{rd()};
        //std::mt19937 gen{BENCHMARK_RANDOM_SEED}; 
       
        std::string mode = "REPLACEME";

        /*
        NBodySystem* system = NBodySystemᘏcreate();
        for(size_t i = 0; i < 500; i++) {
            system = NBodySystemᘏadvance(system, step());
        }
        */

        // Create worklists first (outside timing)
        if(mode == "nbody") {
            auto worklist = nbodyworklist_create(gen);
            nbody_run(worklist);

            calculate_and_print_timing_stats();
        }
        else if(mode == "db") {
            auto worklist = dbworklist_create(gen);
            db_run(worklist);

            calculate_and_print_timing_stats();
        }
        else if(mode == "raytrace") {
            auto worklist = raytraceworklist_create(gen);
            raytrace_run(worklist);

            calculate_and_print_timing_stats();
        }
        else if(mode == "mixed") {
            auto worklist = mixedworklist_create(gen);
            mixed_run(worklist);

            calculate_and_print_timing_stats();
            calculate_and_print_server_stats();
        }
        else {
            std::cout << "failed to run benchmark with flag " << mode << std::endl;
        }
   
        //std::cout << "buckets for given test: " << generate_formatted_memstats(gtl_info.mstats);

        return 0_n;
    }