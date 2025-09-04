# So Long Map Testing Suite

This directory contains a comprehensive set of `.ber` map files for testing the `so_long` game's map validation logic.

## Map Format

The maps use the following characters:
- `1` - Wall
- `0` - Empty space
- `P` - Player (exactly one required)
- `E` - Exit (exactly one required)
- `C` - Collectible (at least one required)

## Validation Requirements

According to the parsing logic in `parsing.c`, a valid map must have:
1. **Exactly one player** (`P`)
2. **Exactly one exit** (`E`)
3. **At least one collectible** (`C`)

## Test Maps

### Valid Maps ✅

1. **`valid_minimal.ber`** - 4x3 map
   - Minimal valid configuration with 1 player, 1 exit, 1 collectible

2. **`valid_small.ber`** - 5x5 map
   - Small map with 1 player, 1 exit, 2 collectibles

3. **`valid_multiple_collectibles.ber`** - 10x10 map
   - Map with 1 player, 1 exit, multiple collectibles scattered around

4. **`valid_large.ber`** - 15x10 map
   - Larger map testing scalability with many collectibles

### Invalid Maps ❌

1. **`invalid_no_player.ber`** - Missing player
   - Should trigger: "No player no game byeeee"

2. **`invalid_no_exit.ber`** - Missing exit
   - Should trigger: "No exit no game byeeee"

3. **`invalid_no_collectibles.ber`** - Missing collectibles
   - Should trigger: "No collectibles no game byeeee"

4. **`invalid_multiple_players.ber`** - Multiple players
   - Should trigger: "Too many players!"

5. **`invalid_multiple_exits.ber`** - Multiple exits
   - Should trigger: "Too many exits!"

6. **`invalid_multiple_players_and_exits.ber`** - Multiple players and exits
   - Should trigger multiple error conditions

7. **`invalid_empty_map.ber`** - No required elements
   - Should trigger: "No player no game byeeee"

## Running Tests

### Manual Testing
Test individual maps:
```bash
./so_long test_maps/valid_minimal.ber
./so_long test_maps/invalid_no_player.ber
```

### Automated Testing
Run the complete test suite:
```bash
./test_map_validation.sh
```

This script will:
- Test all valid maps (expecting success)
- Test all invalid maps (expecting specific error messages)
- Provide a summary of passed/failed tests

## Expected Behavior

### Valid Maps
- Should not print any error messages
- Should proceed to game initialization
- Program should exit cleanly (exit code 0)

### Invalid Maps
- Should print "Error" followed by specific error message
- Should exit with non-zero exit code
- Should not proceed to game initialization

## Error Messages

The validation should produce these specific error messages:
- `"Too many exits!"` - More than one exit found
- `"Too many players!"` - More than one player found
- `"No exit no game byeeee"` - No exit found
- `"No player no game byeeee"` - No player found
- `"No collectibles no game byeeee"` - No collectibles found

## Usage in Development

These test maps are designed to:
1. Verify the `ft_check_EPC()` function works correctly
2. Test edge cases and boundary conditions
3. Ensure error messages are properly displayed
4. Validate that the parsing logic catches all invalid configurations

Add new test cases by creating additional `.ber` files and updating the test script accordingly.
