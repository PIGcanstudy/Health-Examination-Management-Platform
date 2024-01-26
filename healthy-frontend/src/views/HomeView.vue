<template>
  <div class="layout-container">
    <el-container class="sec-container">
      <el-aside :style="{ maxWidth: isCollapsed ? '0' : '221px' }">
        <!-- 侧边栏菜单 -->
        <div class="menu-wrap" :style="isCollapsed ? 'display: none;' : ''">
          <el-scrollbar max-height="100vh">
            <el-menu default-active="/home" class="el-menu-vertical-demo" active-text-color="#409EFF" text-color="#fff" background-color="#545c64" unique-opened router>
              <el-menu-item index="/home">
                <el-icon>
                  <icon-menu />
                </el-icon>
                <span>首页</span>
              </el-menu-item>
              <el-sub-menu v-for="item in menus" :key="item.id" :index="item.id + ''">
                <template #title>
                  <el-icon>
                    <component :is="item.icon" />
                  </el-icon>
                  <span>{{ item.text }}</span>
                </template>
                <el-menu-item-group>
                  <el-menu-item v-for="i in item.children" :key="i.id" :index="i.href">
                    <el-icon>
                      <component :is="i.icon" />
                    </el-icon>
                    {{ i.text }}
                  </el-menu-item>
                </el-menu-item-group>
              </el-sub-menu>
            </el-menu>
          </el-scrollbar>
        </div>
      </el-aside>

      <el-container>
        <!-- 导航栏 -->
        <el-header>
          <el-button class="collBtn" @click="isCollapsed = !isCollapsed">
            <el-icon v-if="!isCollapsed"><icon-arrow-left-bold /></el-icon>
            <el-icon v-if="isCollapsed"><icon-arrow-right-bold /></el-icon>
          </el-button>
          <div>{{ userInfo }}</div>
        </el-header>
        <el-main>
          <!-- 布局路由 -->
          <router-view />
        </el-main>
      </el-container>
    </el-container>
  </div>
</template>
<script setup>
import { ref } from 'vue'
import { userStore } from '../stores/user'
// import { Expand } from '@element-plus/icons-vue'


// 本界面变量及函数
const isCollapsed = ref(false)

const store = userStore()

// 用户信息提示
const userInfo = ref('欢迎用户：' + (store.getUser === null ? '游客' : store.getUser.username))

// 菜单数据
const menus = store.getMenus
</script>
<style lang="scss" scoped>
.sec-container {
  height: 100vh;
}
.el-aside {
  background-color: #545c64;
  .menu-wrap {
    height: 100vh;
    width: 220px;
    position: fixed;
    top: 0;
    left: 0;
  }
}
.el-menu {
  border: 0;
}
.el-menu-item-group .el-menu-item {
  text-indent: 1.5em;
}
.el-main {
  padding: 20px;
}
.el-header {
  background-color: #6c777f;
  color: #f8f8f8;
  display: flex;
  justify-content: space-between;
  align-items: center;
  padding: 0 10px;
  .collBtn {
    width: 32px;
    font-size: 22px;
    color: var(--el-bg-color);
    background: none;
    border: none;
  }
  .collBtn:hover {
    background-color: #545C64;
  }
}
</style>
