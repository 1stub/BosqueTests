#include <mutex>

std::mutex g_mtx;
__CoreCpp::Nat run() noexcept
{
	__CoreCpp::Nat n = /*TREE_DEPTH*/_n;
	__CoreCpp::Nat maxDepth = ( (n < (4_n + 2_n)) ? ((4_n + 2_n)) : (n) );
	__CoreCpp::Nat stretchDepth = (maxDepth + 1_n);
	Tree stretchTree = bottomUpTree(stretchDepth);
	__CoreCpp::Nat stretchCheck = itemCheck(stretchTree);
	Tree longLivedTree = bottomUpTree(maxDepth);
	Core::ListᐸCStringᐳ results = executeDepths(4_n, maxDepth, Core::ListOps::s_list_create_emptyᐸCStringᐳ());
	__CoreCpp::Nat longLivedCheck = itemCheck(longLivedTree);
	return ((stretchCheck + longLivedCheck) + Core::ListᐸCStringᐳᘏsize(results));
}

__CoreCpp::Nat main() noexcept  {
	size_t nthds = /*N_THREADS*/;
	std::thread thds[nthds];

	for(size_t i = 0; i < nthds - 1; i++) {
		thds[i] = std::thread([]() {
			gtl_info.initializeGC(allocs, sizeof(allocs) / sizeof(allocs[0]), false, collect);

			__CoreCpp::Nat res = run();

			std::lock_guard lk(g_mtx);
			std::cout << res << std::endl;
		});
	}

	// Run main thread
	__CoreCpp::Nat res = run();

	for(size_t i = 0; i < nthds - 1; i++) {
		thds[i].join();
	}

	return res;
}
