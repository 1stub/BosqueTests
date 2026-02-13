#include <mutex>

std::mutex g_mtx;
__CoreCpp::Float run(size_t n) noexcept
{
	__CoreCpp::Float step = 0.01_f;

	NBodySystem* system = NBodySystemᘏcreate();
	for(size_t i = 0; i < n; i++) {
		system = NBodySystemᘏadvance(system, step);
	}

	return NBodySystemᘏenergy(system);
}

__CoreCpp::Float main() noexcept  {
	size_t nthds = /*N_THREADS*/;
	std::thread thds[nthds];

	size_t n = /*N_ITERATIONS*/;
	for(size_t i = 0; i < nthds - 1; i++) {
		thds[i] = std::thread([n]() {
			gtl_info.initializeGC(allocs, sizeof(allocs) / sizeof(allocs[0]), collect);

			__CoreCpp::Float res = run(n);

			std::lock_guard lk(g_mtx);
			std::cout << res << std::endl;
		});
	}

	// Run main thread
	__CoreCpp::Float res = run(n);

	for(size_t i = 0; i < nthds - 1; i++) {
		thds[i].join();
	}

	return res;
}
