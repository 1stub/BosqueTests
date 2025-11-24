#!/usr/bin/env python3
import re
import statistics
import sys

def analyze_zgc_pauses(log_file):
    # We'll collect different types of pauses
    mark_start_pauses = []
    mark_end_pauses = [] 
    relocate_start_pauses = []
    allocation_stalls = []
    total_gc_pauses = []  # Sum of all pause phases per GC cycle
    
    # Patterns for different pause types in your log format
    mark_start_pattern = re.compile(r'Pause Mark Start\s+(\d+\.\d+)ms')
    mark_end_pattern = re.compile(r'Pause Mark End\s+(\d+\.\d+)ms')
    relocate_start_pattern = re.compile(r'Pause Relocate Start\s+(\d+\.\d+)ms')
    allocation_stall_pattern = re.compile(r'Allocation Stall.*?(\d+\.\d+)ms')
    
    current_gc_pauses = []  # Track all pauses for current GC cycle
    
    with open(log_file, 'r') as f:
        for line in f:
            line = line.strip()
            
            # Mark Start Pause
            match = mark_start_pattern.search(line)
            if match:
                pause_time = float(match.group(1))
                mark_start_pauses.append(pause_time)
                current_gc_pauses.append(pause_time)
                continue
                
            # Mark End Pause  
            match = mark_end_pattern.search(line)
            if match:
                pause_time = float(match.group(1))
                mark_end_pauses.append(pause_time)
                current_gc_pauses.append(pause_time)
                continue
                
            # Relocate Start Pause
            match = relocate_start_pattern.search(line)
            if match:
                pause_time = float(match.group(1))
                relocate_start_pauses.append(pause_time)
                current_gc_pauses.append(pause_time)
                continue
                
            # Allocation Stall
            match = allocation_stall_pattern.search(line)
            if match:
                pause_time = float(match.group(1))
                allocation_stalls.append(pause_time)
                # Don't add to current_gc_pauses as these are different
                continue
            
            # When we see a new GC start or GC end, finalize current GC cycle
            if 'GC(' in line and ('Garbage Collection' in line or 'GC(start)' in line):
                if current_gc_pauses:
                    total_gc_pauses.append(sum(current_gc_pauses))
                    current_gc_pauses = []
    
    # Don't forget the last GC cycle
    if current_gc_pauses:
        total_gc_pauses.append(sum(current_gc_pauses))
    
    def print_percentiles(data, name):
        if not data:
            print(f"No {name} data found")
            return
            
        sorted_data = sorted(data)
        n = len(sorted_data)
        
        percentiles = {
            '50th': sorted_data[int(0.50 * n) - 1] if n > 0 else 0,
            '75th': sorted_data[int(0.75 * n) - 1] if n > 1 else sorted_data[0],
            '90th': sorted_data[int(0.90 * n) - 1] if n > 1 else sorted_data[0],
            '95th': sorted_data[int(0.95 * n) - 1] if n > 1 else sorted_data[0],
            '99th': sorted_data[int(0.99 * n) - 1] if n > 1 else sorted_data[0],
        }
        
        print(f"\n=== {name} ===")
        print(f"Count: {n}")
        print(f"Min: {min(data):.3f}ms")
        print(f"Max: {max(data):.3f}ms")
        print(f"Mean: {statistics.mean(data):.3f}ms")
        for p_name, p_value in percentiles.items():
            print(f"{p_name} percentile: {p_value:.3f}ms")
    
    print("ZGC Pause Time Analysis")
    print("=" * 50)
    
    print_percentiles(mark_start_pauses, "Mark Start Pauses")
    print_percentiles(mark_end_pauses, "Mark End Pauses") 
    print_percentiles(relocate_start_pauses, "Relocate Start Pauses")
    print_percentiles(allocation_stalls, "Allocation Stalls")
    print_percentiles(total_gc_pauses, "Total GC Pauses (Sum of all phases)")
    
    # Also show concurrent phase times for context
    concurrent_mark_pattern = re.compile(r'Concurrent Mark\s+(\d+\.\d+)ms')
    concurrent_relocate_pattern = re.compile(r'Concurrent Relocate\s+(\d+\.\d+)ms')
    
    concurrent_marks = []
    concurrent_relocates = []
    
    with open(log_file, 'r') as f:
        for line in f:
            match = concurrent_mark_pattern.search(line)
            if match:
                concurrent_marks.append(float(match.group(1)))
            
            match = concurrent_relocate_pattern.search(line)
            if match:
                concurrent_relocates.append(float(match.group(1)))
    
    if concurrent_marks:
        print(f"\nConcurrent Mark times: {statistics.mean(concurrent_marks):.1f}ms avg")
    if concurrent_relocates:
        print(f"Concurrent Relocate times: {statistics.mean(concurrent_relocates):.1f}ms avg")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python3 analyze_zgc_pauses.py <gc-log-file>")
        sys.exit(1)
    
    analyze_zgc_pauses(sys.argv[1])