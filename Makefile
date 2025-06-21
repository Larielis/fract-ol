CC        = cc
CFLAGS    = -Wall -Wextra -Werror -MMD -MP

NAME      = fract-ol
SRC_DIR   = srcs
OBJ_DIR   = objs
INC_DIR   = includes

LIBMLX    = MLX42
BUILD_MLX = $(LIBMLX)/build

SRC  = $(SRC_DIR)/main.c \
		$(SRC_DIR)/julia.c \
		$(SRC_DIR)/mandelbrot.c \
		$(SRC_DIR)/hooks.c \
		$(SRC_DIR)/setup.c \
		$(SRC_DIR)/init.c \
		$(SRC_DIR)/pan.c \
		$(SRC_DIR)/scroll.c \
		$(SRC_DIR)/context.c \
		$(SRC_DIR)/utils/utils.c \
		$(SRC_DIR)/utils/image_utils.c \
		$(SRC_DIR)/utils/ft_strcmp.c \
		$(SRC_DIR)/utils/ft_memset.c \
		$(SRC_DIR)/utils/ft_strlen.c \
		$(SRC_DIR)/utils/ft_atof.c \
		$(SRC_DIR)/utils/ft_isdigit.c \
		$(SRC_DIR)/utils/ft_isspace.c

OBJS      = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS      = $(OBJS:.o=.d)

HEADERS   = -I$(INC_DIR) -I$(LIBMLX)/include
LIBS      = $(BUILD_MLX)/libmlx42.a -lglfw -ldl -lm -pthread

all: libmlx $(NAME)

libmlx:
	@cmake -S $(LIBMLX) -B $(BUILD_MLX) -DCMAKE_BUILD_TYPE=Release
	@cmake --build $(BUILD_MLX) --target mlx42

$(NAME): $(OBJS)
	@echo "Linking $@…"
	@$(CC) $(CFLAGS) $(HEADERS) $(OBJS) $(LIBS) -o $@
	@echo "Built $@"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR) $(BUILD_MLX)
	@echo "Cleaned objects and MLX42 build"

fclean: clean
	@rm -f $(NAME)
	@echo "Removed $(NAME)"

re: fclean all

-include $(DEPS)

.PHONY: all libmlx clean fclean re
