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
              <el-sub-menu v-for="item in menu" :key="item.id" :index="item.id + ''">
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
          <!-- 伸缩按钮 -->
          <el-button class="collBtn" @click="isCollapsed = !isCollapsed">
            <el-icon v-if="!isCollapsed"><icon-arrow-left-bold /></el-icon>
            <el-icon v-if="isCollapsed"><icon-arrow-right-bold /></el-icon>
          </el-button>

          <!-- 下拉菜单 -->
          <!-- TODO 路由菜单导航还需完善-->
          <el-dropdown>
            <span class="el-dropdown-link">
              系统菜单
              <el-icon class="el-icon--right">
                <arrow-down />
              </el-icon>
            </span>
            <template #dropdown>
              <el-dropdown-menu style="display: ">
                <router-link to="/home"><el-dropdown-item>基础数据</el-dropdown-item></router-link>
                <router-link to="/"><el-dropdown-item>营销管理</el-dropdown-item></router-link>
                <router-link to="/"><el-dropdown-item>体检登记</el-dropdown-item></router-link>
                <router-link to="/"><el-dropdown-item>结果录入</el-dropdown-item></router-link>
                <router-link to="/"><el-dropdown-item>主检评价</el-dropdown-item></router-link>
                <router-link to="/"><el-dropdown-item>配置管理</el-dropdown-item></router-link>
                <router-link to="/"><el-dropdown-item>系统配置</el-dropdown-item></router-link>
                <router-link to="/"><el-dropdown-item>数据网报</el-dropdown-item></router-link>
                <router-link to="/"><el-dropdown-item>查询统计</el-dropdown-item></router-link>
              </el-dropdown-menu>
            </template>
          </el-dropdown>

          <!-- 用户信息 -->
          <el-dropdown class="ml-2">
            <el-button type="" circle>
              <el-icon :size="20">
                <UserFilled />
              </el-icon>
            </el-button>
            <template #dropdown>
              <el-dropdown-menu>
                <el-dropdown-item>个人中心</el-dropdown-item>
                <el-dropdown-item>修改密码</el-dropdown-item>
                <el-dropdown-item>退出登录</el-dropdown-item>
              </el-dropdown-menu>
            </template>
          </el-dropdown>
          <div>{{ userInfo }}</div>
        </el-header>
        <el-main style="padding: 0">
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
import { ArrowDown } from '@element-plus/icons-vue'


import { Check, CircleCheck, CirclePlus, CirclePlusFilled, Plus } from '@element-plus/icons-vue'
import testMenus from '../stores/menus/healthcheck'
// import { Expand } from '@element-plus/icons-vue'

// 本界面变量及函数
const isCollapsed = ref(false)
//定义仓库
const store = userStore()

// 用户信息提示
const userInfo = ref('欢迎用户：' + (store.getUser === null ? '游客' : store.getUser.username))

// 首页菜单数据e
const menu = store.getMenus
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
  // background-color: #6c777f;
  border-bottom: solid 1px var(--el-border-color);
  color: #f8f8f8;
  display: flex;
  justify-content: space-between;
  align-items: center;
  padding: 0 10px;
 .el-dropdown {
  }
  .collBtn {
    width: 32px;
    font-size: 22px;
    color: var(--el-bg-color);
    background: none;
    border: none;
  }
  .collBtn:hover {
    background-color: #545c64;
  }
}
</style>
