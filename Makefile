BUILD_DIR = build
EXECUTABLE_NAME = shell
.PHONY: all clean rebuild test install run

all:
	@mkdir -p $(BUILD_DIR)
	@cd $(BUILD_DIR) && cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .. && make
# symlink the compile_commands to root dir for lsp
	@ln -sf $(BUILD_DIR)/compile_commands.json .

clean:
	@rm -rf $(BUILD_DIR)
	@rm -f compile_commands.json

rebuild: clean all

test:
	@cd $(BUILD_DIR) && ctest --output-on-failure

install:
	@cd $(BUILD_DIR) && make install

run:
	@cd $(BUILD_DIR)/bin && ./${EXECUTABLE_NAME}
