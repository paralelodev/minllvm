# Minllvm

This is a project that tries to replicate the concepts of Module, Function and Basic Block from LLVM.

## How to compile

```bash
git clone https://github.com/paralelodev/minllvm.git
cd minllvm
cmake . -G Ninja -B build
cd build
ninja
```

## How to test

### Errors

```bash
cd test/errors
./insert_duplicated_element
./insert_duplicated_tag
./remove_inexistent_element
./insert_to_inexistent_predecessor
```

### Invalid function

```bash
cd test/invalid_function
./empty_function
./inexistent_entry_block
./unreacheable_block
```

### Valid function

```bash
cd test/valid_function
./valid_0
./valid_1
```


