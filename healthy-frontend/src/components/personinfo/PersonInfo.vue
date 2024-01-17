<template>
    <!-- 人员信息 -->
    <div>
        <el-tabs type="border-card">
            <el-tab-pane label="男">
                <el-table 
                    :data="personInfo"
                    border
                    :cell-style="{ textAlign: 'center' }"
                    :header-cell-style="{ 'text-align': 'center' }"
                    style="width: 100%;margin-top: 10px;"
                >
                    <el-table-column type="selection" width="60" />
                    <el-table-column prop="name" label="姓名" />
                    <el-table-column prop="result" label="性别" />
                    <el-table-column prop="reference" label="证件号码" />
                    <el-table-column prop="unit" label="年龄" />
                    <el-table-column prop="prompt" label="操作">
                        <template #default="scope">
                            <el-button-group class="ml-4">
                                <el-button size="small" @click="handleEdit(scope.$index, scope.row)">
                                    <el-icon>
                                        <icon-view />
                                    </el-icon>
                                </el-button>
                                <el-button size="small" @click="handleEdit(scope.$index, scope.row)">
                                    <el-icon>
                                        <icon-edit />
                                    </el-icon>
                                </el-button>
                                <el-button size="small" type="danger" @click="handleEdit(scope.$index, scope.row)">
                                    <el-icon>
                                        <icon-delete />
                                    </el-icon>
                                </el-button>
                            </el-button-group>
                        </template>
                    </el-table-column>
                </el-table>

                <el-pagination
                    v-model:current-page="currentPage"
                    v-model:page-size="pageSize"
                    :page-sizes="[10, 20, 50]"
                    :small="false"
                    :disabled="disabled"
                    :background="background"
                    layout="total, sizes, prev, pager, next, jumper"
                    :total="200"
                    @size-change="handleSizeChange"
                    @current-change="handleCurrentChange"
                    style="margin-top: 10px;justify-content: flex-end;"
                />
            </el-tab-pane>
            <el-tab-pane label="女">
                
            </el-tab-pane>
        </el-tabs>
    </div>
</template>

<script setup>
import { defineProps } from 'vue'
import { ref } from 'vue'

// 分页相关
const currentPage = ref(1)
const pageSize = ref(10)

const props = defineProps({
    personInfo: {
        type: Array,
        default: () => []
    }
})
</script>

<style lang="scss" scoped></style>
