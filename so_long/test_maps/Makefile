# Test targets for so_long map validation

.PHONY: test test-valid test-invalid clean

# Run all tests
test:
	@echo "Running complete map validation test suite..."
	@../test_map_validation.sh

# Test only valid maps
test-valid:
	@echo "Testing valid maps..."
	@for map in valid_*.ber; do \
		echo "Testing $$map..."; \
		../so_long "$$map" && echo "✅ PASS" || echo "❌ FAIL"; \
	done

# Test only invalid maps
test-invalid:
	@echo "Testing invalid maps..."
	@for map in invalid_*.ber; do \
		echo "Testing $$map..."; \
		../so_long "$$map" 2>/dev/null && echo "❌ FAIL (should be invalid)" || echo "✅ PASS (correctly rejected)"; \
	done

# List all test maps
list:
	@echo "Available test maps:"
	@echo "Valid maps:"
	@ls -1 valid_*.ber 2>/dev/null || echo "  None found"
	@echo "Invalid maps:"
	@ls -1 invalid_*.ber 2>/dev/null || echo "  None found"

# Clean any temporary files
clean:
	@echo "No temporary files to clean in test directory"
