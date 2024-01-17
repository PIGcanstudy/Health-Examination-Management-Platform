<template>
  <div class="container">
    <!-- 列表名称区域 -->
    <el-card class="top">
      <div class="list-name">
        <span>人员列表</span>
      </div>
    </el-card>

    <!-- 主体部分 -->
    <el-card class="body" shadow="hover">
      <!-- 表单控件区域 -->
      <div class="form-area">
        <el-form :model="form">
          <el-form-item>
            <el-radio-group v-model="form.resource" style="margin-right: auto">
              <el-radio label="已检" />
              <el-radio label="未检" />
            </el-radio-group>
            <el-switch v-model="slider" inline-prompt active-text="复查" inactive-text="非复"></el-switch>
          </el-form-item>

          <el-form-item>
            <el-row clearable>
              <el-date-picker v-model="form.startDate" style="width: 49%" type="date" placeholder="开始时间" />
              <span style="width: 2%">~</span>
              <el-date-picker v-model="form.endDate" style="width: 49%" type="date" placeholder="结束时间" />
            </el-row>
          </el-form-item>

          <el-form-item>
            <el-input v-model="form.name" placeholder="请输入姓名" clearable />
          </el-form-item>
          <!-- 点击按钮折叠区域 -->
          <div v-if="isShowInput">
            <el-form-item>
              <el-input v-model="form.serialNumber" placeholder="请输入体检编号" clearable />
            </el-form-item>
            <el-form-item>
              <el-input v-model="form.workplace" placeholder="请输入单位名称" clearable></el-input>
            </el-form-item>
          </div>
          <el-form-item>
            <el-button type="primary" @click="onSubmit">查询</el-button>
            <el-button plain @click="resetForm">重置</el-button>
            <div>
              <el-button type="text" style="margin-left: 14px" @click="toggleCollapse"
                >{{ isShowInput ? '收起' : '展开' }}
                <el-icon v-show="isShowInput === true"><ArrowUp /></el-icon>
                <el-icon v-show="isShowInput === false"><ArrowDown /></el-icon>
              </el-button>
            </div>
          </el-form-item>
        </el-form>
      </div>

      <!-- 表格数据区域 -->
      <div class="table-area">
        <el-table
          ref="multipleTableRef"
          v-loading="loading"
          height="300"
          :data="tableData"
          :show-header="false"
          highlight-current-row
          @selection-change="handleSelectionChange"
          @row-click="selectClick"
        >
          <el-table-column type="index" width="40%" />
          <el-table-column property="name" width="80%">
            <!-- <template>{{ scope.row.name }}</template> -->
          </el-table-column>
          <el-table-column property="gender" width="45%">
            <!-- <template>{{ scope.row.gender }}</template> -->
          </el-table-column>
          <el-table-column property="age" width="45%">
            <!-- <template>{{ scope.row.age }}</template> -->
          </el-table-column>
          <el-table-column>
            <el-tag type="success" style="margin-right: 4px">健</el-tag>
            <el-tag type="danger">零</el-tag>
          </el-table-column>
        </el-table>
      </div>

      <!-- 分页区域 -->
      <el-pagination
        v-model:current-page="currentPage"
        v-model:page-size="pageSize"
        class="paginaiton"
        layout="prev, jumper, pager, next, "
        :total="100"
        pager-count="2"
        style="justify-content: center; margin-top: 30px; padding-right: 1px"
        @size-change="handleSizeChange"
        @current-change="handleCurrentChange"
      />
    </el-card>
  </div>
</template>

<script setup>
import { ref } from 'vue'
import { ArrowUp, ArrowDown } from '@element-plus/icons-vue'

// 滑块开关逻辑
const slider = ref(true)

// 表单验证逻辑
const form = ref({
  name: '',
  serialNumber: '',
  startDate: '',
  endDate: '',
  resource: ''
})

// 提交表单查询逻辑
const onSubmit = () => {
  console.log('submit')
}
// 重置表单逻辑
const resetForm = () => {
  console.log('reset')
}
// 点击按钮折叠逻辑
const isShowInput = ref(false)
const toggleCollapse = () => {
  isShowInput.value = !isShowInput.value
}

// 页面加载逻辑
const loading = ref(false)

// 表格数据存放区域
const tableData = [
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tags: '健'
  },
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tags: '零'
  },
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tags: '零'
  },
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tags: '零'
  },
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tags: '零'
  },
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tags: '零'
  },
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tags: '零'
  },
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tags: '零'
  },
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tags: '零'
  },
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tags: '零'
  }
]

// 分页逻辑
const currentPage = ref(1)
const handleSizeChange = (size) => {
  console.log('当前每页条数', size)
}
const handleCurrentChange = (page) => {
  console.log('页码发生变化', page)
}

// v-shoe/v-if测试区域
</script>

<style lang="scss" scoped>
.container {
  height: 750px;
  width: 24%;
  margin-bottom: 0%;
}
.top {
  text-align: center;
  background-color: rgb(240, 250, 255);

  span {
    color: rgb(81, 90, 110);
    font-weight: 550;
  }
}
.body {
  height: 100%;
}
.pagination {
  position: absolute;
  bottom: 10px;
}
</style>
