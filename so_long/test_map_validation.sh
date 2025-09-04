#!/bin/bash

# Test script for so_long map validation
# This script tests various .ber maps to ensure the parsing logic works correctly

echo "=== Testing so_long Map Validation ==="
echo

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

test_count=0
passed_count=0

# Function to test a map file
test_map() {
    local map_file="$1"
    local expected_result="$2"  # "valid" or "invalid"
    local description="$3"

    ((test_count++))
    echo -e "${BLUE}Test $test_count:${NC} $description"
    echo "File: $map_file"

    if [ ! -f "$map_file" ]; then
        echo -e "${RED}FAIL:${NC} Map file does not exist"
        echo
        return
    fi

    # Run the so_long program with the map file
    # Capture both stdout and stderr
    output=$(./so_long "$map_file" 2>&1)
    exit_code=$?

    if [ "$expected_result" = "valid" ]; then
        if [ $exit_code -eq 0 ] && [[ ! "$output" =~ "Error" ]]; then
            echo -e "${GREEN}PASS:${NC} Map correctly validated as valid"
            ((passed_count++))
        else
            echo -e "${RED}FAIL:${NC} Map should be valid but was rejected"
            echo "Output: $output"
        fi
    else
        if [ $exit_code -ne 0 ] || [[ "$output" =~ "Error" ]]; then
            echo -e "${GREEN}PASS:${NC} Map correctly rejected as invalid"
            ((passed_count++))
        else
            echo -e "${RED}FAIL:${NC} Map should be invalid but was accepted"
            echo "Output: $output"
        fi
    fi
    echo
}

# Check if so_long executable exists
if [ ! -f "./so_long" ]; then
    echo -e "${RED}Error:${NC} so_long executable not found. Please compile first with 'make'"
    exit 1
fi

echo "Testing valid maps..."
echo "==================="

test_map "test_maps/valid_minimal.ber" "valid" "Minimal valid map (1 player, 1 exit, 1 collectible)"
test_map "test_maps/valid_small.ber" "valid" "Small valid map (1 player, 1 exit, 2 collectibles)"
test_map "test_maps/valid_multiple_collectibles.ber" "valid" "Valid map with multiple collectibles"
test_map "test_maps/valid_large.ber" "valid" "Large valid map"

echo "Testing invalid maps..."
echo "======================"

test_map "test_maps/invalid_no_player.ber" "invalid" "Map with no player"
test_map "test_maps/invalid_no_exit.ber" "invalid" "Map with no exit"
test_map "test_maps/invalid_no_collectibles.ber" "invalid" "Map with no collectibles"
test_map "test_maps/invalid_multiple_players.ber" "invalid" "Map with multiple players"
test_map "test_maps/invalid_multiple_exits.ber" "invalid" "Map with multiple exits"
test_map "test_maps/invalid_multiple_players_and_exits.ber" "invalid" "Map with multiple players and exits"
test_map "test_maps/invalid_empty_map.ber" "invalid" "Map with no required elements"

echo "=== Test Results ==="
echo "Passed: $passed_count/$test_count"
if [ $passed_count -eq $test_count ]; then
    echo -e "${GREEN}All tests passed!${NC}"
    exit 0
else
    echo -e "${RED}Some tests failed.${NC}"
    exit 1
fi
